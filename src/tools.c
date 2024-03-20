#include "tools.h"

//#define _DEBUG_
#ifdef _DEBUG_
Process processes[10000];
DayArrange day[10000];
int endPeiod;
time_t startPeiod;

int main(){
}
#endif

int streq(const char* a, const char* b) {
  return !memcmp(a, b, sizeof(char) * strlen(b));
}

char** genCommand(char* str, int* len) {
  char** result = malloc(10*sizeof(char));
  int l = 0;

  char *token = strtok(str, " ");
  while( token != NULL ) {
    result[l++] = token;
    token = strtok(NULL, " ");
  }
  *len = l;
  return result;
}

int checkCommand(char* str) {
  if (streq(str, "addPEIOD"))
    return 0;
  if (streq(str, "addORDER"))
    return 1;
  if (streq(str, "addBATCH"))
    return 2;
  if (streq(str, "runPLS"))
    return 3;
  if (streq(str, "exitPLS"))
    return 4;
  return -1;
}

int commandAlg(char* alg) {
  if (streq(alg, "FCFS"))
    return 0;
  if (streq(alg, "PR"))
    return 1;
  return -1;
}

int hasFile(char* str) {
  return 0;
}

int timeToInt(char* str) {
  struct tm tm;
  memset(&tm, 0, sizeof(tm));
  sscanf(str, "%4d-%2d-%2d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
  tm.tm_year -= 1900;
  tm.tm_mon -= 1;
  return (int)(difftime(mktime(&tm), startPeiod)/86400 + 0.5);
}

char* intToTime(int i) {
  char* str = malloc(20*sizeof(char));
  struct tm tm = *(localtime(&startPeiod));
  tm.tm_mday += i;
  mktime(&tm);
  sprintf(str, "%04d-%02d-%02d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
  return str;
}

void printMenu(){

}

void errorAlg(char* str) {
  printf("runPLS: %s: algorithm not found\n", str);
}

void errorCommand(char* str) {
  printf("%s: command not found\n", str);
}

void errorUsage(int c) {
  switch (c) {
  case 3:
    printf("Usage: runPLS ALGORITHM [| printREPORT [> FILENAME]]\n");
    printf("generate a schedule with the specified ALGORITHM.\n");
  }
}
