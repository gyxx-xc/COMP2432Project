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

int command(char* str) {
  if (!memcmp(str, "addPEIOD", sizeof("addPEIOD")))
    return 0;
  if (!memcmp(str, "addORDER", sizeof("addORDER")))
    return 1;
  if (!memcmp(str, "addBATCH", sizeof("addBATCH")))
    return 2;
  if (!memcmp(str, "runPLS", sizeof("runPLS")))
    return 3;
  if (!memcmp(str, "exitPLS", sizeof("exitPLS")))
    return 4;
  return -1;
}

int commandAlg(char* str) {
  char alg[10];
  sscanf(str, "%s%s", 0, alg);
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
