#include <stdio.h>
#include <sys/wait.h>

#include "tools.h"
#include "input.h"
#include "output.h"
#include "runpls.h"

Process processes[10000];
DayArrange day[10000];
int endPeiod;

// do not use this varible
// only used by utils of time
// the usage of time function refer to tools.h
time_t startPeiod;

int main() {
  while(1) {
    printMenu();
    char str[200];
    fgets(str, 200, stdin);
    int commandLen;
    char** command = genCommand(str, &commandLen);
    if (commandLen == 0) continue; // why?
    switch(checkCommand(command[0])) {
    case 0:
      addPEIOD(command);
      break;
    case 1:
      addORDER(command);
      break;
    case 2:
      addBATCH(command);
      break;
    case 3:
      if (checkRunUsage(command, commandLen)) errorUsage(3);
      int algTemp = commandAlg(command[1]);
      if (!~algTemp) {
        errorAlg(command[1]);
        break;
      }

      runPLS(algTemp);

      if (commandLen < 3) break; // why?
      int fd[2];
      int p = createChild(fd);
      if (p == 0) { // child
        if (commandLen >= 6) {
          FILE* file = fopen(command[5], "w");
          printREPORT(fd, file);
        } else {
          printREPORT(fd, stdout);
        }

      } else { // parent
        sendData(p, fd);
      }
      break;
    case 4:
      return 0; // exitPLS
    case -1:
      errorCommand(command[0]);
      break;
    }
  }
}
