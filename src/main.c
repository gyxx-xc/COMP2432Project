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
    char str[100];
    fgets(str, 100, stdin);
    switch(command(str)) {
    case 0:
      addPEIOD();
      break;
    case 1:
      addORDER(str);
      break;
    case 2:
      addBATCH(str);
      break;
    case 3:
      runPLS(commandAlg(str));
      int fd[2];
      int p = createChild(fd);
      if (p == 0) { // child
        if (hasFile(str)) {
          FILE* file = fopen(str, "w");
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
    }
  }
}
