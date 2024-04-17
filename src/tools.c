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
  if (strlen(a) != strlen(b)) return 0;
  return !memcmp(a, b, sizeof(char) * strlen(b));
}

char** genCommand(char* str, int* len) {
  char** result = malloc(10*sizeof(char *));
  int l = 0;

  if (str[strlen(str) - 1] == '\n' ||
      str[strlen(str) - 1] == '\r')
    str[strlen(str) - 1] = 0; // remove the \r
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
  if (streq(str, "addPERIOD"))
    return 0;
  return -1;
}

int commandAlg(char* alg) {
  if (streq(alg, "FCFS"))
    return 0;
  if (streq(alg, "PR"))
    return 1;
  if (streq(alg, "CDF"))
    return 2;
  return -1;
}

void initTime(char* startTime) {
  struct tm tm;
  memset(&tm, 0, sizeof(tm));
  strptime(startTime, "%Y-%m-%d", &tm);
  startPeiod = mktime(&tm);
}

int timeToInt(char* str) {
  struct tm tm;
  memset(&tm, 0, sizeof(tm));
  strptime(str, "%Y-%m-%d", &tm);
  return (int)(difftime(mktime(&tm), startPeiod)/86400 + 0.5);
}

char* intToTime(int i) {
  char* str = malloc(20*sizeof(char));
  struct tm tm = *(localtime(&startPeiod));
  tm.tm_mday += i;
  mktime(&tm);
  strftime(str, 20, "%Y-%m-%d", &tm);
  return str;
}

void printMenu(){
  printf("Please enter:\n> ");
}

void errorAlg(char* str) {
  printf("runPLS: %s: algorithm not found\n", str);
}

void errorCommand(char* str) {
  printf("%s: command not found\n", str);
}

void errorUsage(int c) {
  switch (c) {
  case 0:
    printf("Usage: addPERIOD start_date end_date\n");
    printf("specify the period for scheduling the production\n");
  case 1:
    printf("Usage: addORDER order_number due_date quantity product_name\n");
    printf("add an order and the details to the scheduler.\n");
  case 2:
    printf("Usage: addBATCH filename\n");
    printf("input multiple orders in one batch file.\n");
  case 3:
    printf("Usage: runPLS algorithm | printREPORT [> filename]\n");
    printf("generate a schedule with the specified algorithm.\n");
  }
}

int checkRunUsage (char** c, int l) {
  if (l < 4) return l == 2;
  if (!streq(c[2], "|") || !streq(c[3], "printREPORT")) return 0;
  if (l < 6) return l == 4;
  if (!streq(c[4], ">")) return 0;
  return l == 6;
}
