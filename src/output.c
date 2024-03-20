#include "output.h"

//#define _DEBUG_ // to debug uncomment this line and run `gcc output.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[10000];
int dayCount;
int endPeiod;
time_t startPeiod;

int main(){
  // set day...
  // call algrothm
  // print some debug output
}
#endif


// create children and pipe
// the pid is the return value and the pipe store to fd
int createChild(int* fd) {
  return 0;
}

// child process
// read the `day` from pipe here
// the function intToTime in `tools.h` may useful
void printREPORT(int* fd, FILE* file) {
  fprintf(file, "123123123\n");
}

// parent process
// write the `day` into the pipe here
// you can access the `day` as a globle varible
// remember to wait the children
void sendData(int pid, int* fd) {

}
