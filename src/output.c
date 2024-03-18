#include "output.h"

// create children and pipe
// the pid is the return value and the pipe store to fd
int createChild(int* fd) {
  return 0;
}

// child process
// read the `day` from pipe here
// the function intToTime may useful
void printREPORT(int* fd, FILE* file) {
  fprintf(file, "123123123\n");
}

// parent process
// write the `day` into the pipe here
// you can access the `day` as a globle varible
// remember to wait the children
void sendData(int pid, int* fd) {

}
