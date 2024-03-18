#include "tools.h"

//#define _DEBUG_
#ifdef _DEBUG_
Process processes[10000];
DayArrange day[10000];
int endPeiod;
time_t startPeiod;

int main(){
  struct tm tm;
  memset(&tm, 0, sizeof(tm));
  tm.tm_year = 2003 - 1900;
  tm.tm_mon = 2 - 1;
  tm.tm_mday = 29;
  startPeiod = mktime(&tm);
  char i[100];
  scanf("%s", i);
  printf("%s\n", intToTime(timeToInt(i)));
}
#endif

int command(char* str) {
  return 1;
}

int commandAlg(char* str) {
  return 1;
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
