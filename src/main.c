#include <stdio.h>
#include <sys/wait.h>

#include "tools.h"
#include "input.h"
#include "output.h"
#include "runpls.h"

Process processes[10000];
int processesCount;
DayArrange day[3][10000];
int dayCount[3];
int endPeiod;

// do not use this varible
// only used by utils of time
// the usage of time function refer to tools.h
time_t startPeiod;

int main() {
  printf("\t~~WELCOME TO PLS~~\n\n");
  while (1) {
    printMenu();
    char str[100];
    char* result = fgets(str, 100, stdin);
    if (result == NULL)
      return 0;
    int commandLen;
    char **command = genCommand(str, &commandLen);
    if (commandLen == 0)
      continue; // why?
    switch (checkCommand(command[0])) {
    case 0:
      addPEIOD(command, commandLen);
      break;
    case 1:
      addORDER(command, commandLen);
      break;
    case 2:
      addBATCH(command, commandLen);
      break;
    case 3:
      if (!checkRunUsage(command, commandLen)) {
        errorUsage(3);
        break;
      }

      int algTemp = commandAlg(command[1]);
      if (!~algTemp) {
        errorAlg(command[1]);
        break;
      }
      runPLS(algTemp);

      if (commandLen >= 6) {
        FILE *file = fopen(command[5], "w");
        printREPORT(file, algTemp);
      } else {
        printREPORT(stdout, algTemp);
      }
      memset(day, 0, sizeof(day));
      memset(dayCount, 0, sizeof(dayCount));
      break;
    case 4:
      printf("Bye-bye!\n");
      return 0; // exitPLS
    case -1:
      errorCommand(command[0]);
      break;
    }
    free(command);
  }
}
