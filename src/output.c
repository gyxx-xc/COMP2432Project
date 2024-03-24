#include "output.h"
#include <unistd.h>

#define _DEBUG_ // to debug uncomment this line and run `gcc output.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[10000];
int dayCount;
int endPeiod;
time_t startPeiod;

int main()
{
  int fd[2];
  int p = createChild(fd);
  printf("%d\n", p);
  // set day...
  // call algrothm
  // print some debug output
}
#endif

// create children and pipe
// the pid is the return value and the pipe store to fd
int createChild(int *fd)
{
  int pipefd[2];
  if (pipe(pipefd) == -1)
  {
    perror("pipe");
    return -1;
  }

  pid_t pid = fork();
  if (pid == -1)
  {
    perror("fork");
    close(pipefd[0]);
    close(pipefd[1]);
    return -1;
  }
  else if (pid == 0)
  {
    // 子进程
    close(pipefd[1]);  // 关闭子进程中的写入端
    fd[0] = pipefd[0]; // 将管道的读取端传递给父进程
    printf("childprocess\n");
    return pid;
  }
  else
  {
    // 父进程
    close(pipefd[0]);  // 关闭父进程中的读取端
    fd[1] = pipefd[1]; // 将管道的写入端传递给子进程
    printf("parentprocess\n");
    return pid;
  }
}

// child process
// read the `day` from pipe here
// the function intToTime in `tools.h` may useful
void printREPORT(int *fd, FILE *file)
{
  fprintf(file, "123123123\n");
}

// parent process
// write the `day` into the pipe here
// you can access the `day` as a globle varible
// remember to wait the children
void sendData(int pid, int *fd)
{
}
