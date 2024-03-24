#include "output.h"
#include <unistd.h>

// #define _DEBUG_ // to debug uncomment this line and run `gcc output.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[10000];
int dayCount;
int endPeiod;
time_t startPeiod;

int main()
{
  printREPORT(stdout);
}
#endif

// create children and pipe
// the pid is the return value and the pipe store to fd
/*
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
    int fd[2];
    int p = createChild(fd);
    printf("%d\n", p);
    // set day...
    // call algrothm
    // print some debug output
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
*/
// child process
// read the `day` from pipe here
// the function intToTime in `tools.h` may useful
void printREPORT(FILE *file ,int alg)
{
  Process rejectedProcesses[10000];
  char Algorithm;
  int rejectedCount = 0;
  char c[100];
  int startTime = 0;
  int endTime;
  char plant[7];
  for(int i = 0;i < processesCount;i++){
    if(processes[i].accepted == 0){
      rejectedProcesses[i] = processes[i];
    }
  }
  if(alg = 0){
    Algorithm = "FCFS";
  }
  else{
    Algorithm = "PR"
  };
  printf("Algorithm used: %c\n",Algorithm);
  printf("There are %d Orders ACCEPTED.", acceptedCount);
  printf(" Details are as follows: \n");
  printf("ORDER NUMBER   START        END         DAYS    QUANTITY    PLANT\n");
  for(int i = 0 ;i < 3; i++){
    c = day[i][0].Product.orderNumber;
    switch (i)
    {
    case 0:
      plant = "PLANT_X";
      break;
    case 1:
      plant = "PLANT_Y";
      break;
    case 2:
      plant = "PLANT_Z";
      break;
    default:
      break;
    }
    for(int j = 0;i < dayCount){
      int check = memccpy(c,day[i][j].Product.orderNumber,sizeof(c));
      if(check == 0){
        
      }
      else{
        c = day[i][j].Product.orderNumber;
        endTime = j-1;
        int days = endTime - startTime;
        printf("%c %c %c %d %d %c",day[i][j].Product.orderNumber,intToTime(startTime),intToTime(endTime),days,day[i][j].producedQuantity,plant)
      }
    }
  


  // here for parent to analyse.
  int parent_to_child[3][2];
  int child_to_parent[3][2];
  for (int i = 0; i < 3; i++)
  {
    pid_t pid = fork();

    if (pid < 0)
    {
      printf("Fork failed\n");
      exit(1);
    }
    else if (pid == 0) // Child process
    {
    }
  }
  fprintf(file, "123123123\n");
  }
}

// parent process
// write the `day` into the pipe here
// you can access the `day` as a globle varible
// remember to wait the children
void sendData(int pid, int *fd)
{
}
