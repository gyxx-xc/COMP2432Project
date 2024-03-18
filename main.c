#include <stdio.h>
#include <sys/wait.h>

#ifndef TOOLS_H
#define TOOLS_H
#include "tools.h"
#endif

#include "input.h"
#include "output.h"
#include "runpls.h"

int main() {
  while(1) {
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
      runPLS(commandAlg(str), processes, day);
      int fd[2];
      int p = createChild(fd);
      if (p != 0) {
        if (hasFile(str)){
          FILE* file = fopen(str, "w");
          printREPORT(fd, file);
        }else
          printREPORT(fd, stdout);
      } else {
        wait(0);
      }
      break;
    case 4:
      return 0; // exitPLS
    }
  }
}
