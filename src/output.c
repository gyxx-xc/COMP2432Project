#include "output.h"
#include <unistd.h>

#define _DEBUG_ // to debug uncomment this line and run `gcc output.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[3][10000];
int dayCount[3];
int endPeiod;
time_t startPeiod;

int main()
{
  initTime("2023-12-30");
  char a[10] = "P0000";
  for (int i = 0; i < 10; i++)
  {
    day[i % 3][dayCount[i % 3]++] = (DayArrange){
        (Process){0, i, 100 * i ^ 3, i % 9, 0, 1},
        100};
    memcpy(day[i % 3][dayCount[i % 3] - 1].Product.orderNumber, a, sizeof(a));
    a[4]++;
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < dayCount[i % 3]; j++)
    {
      printf("%s ", day[i][j].Product.orderNumber);
    }
    printf("\n");
  }
  printREPORT(stdout, 0);
}
#endif

// child process
// read the `day` from pipe here
// the function intToTime in `tools.h` may useful
void printREPORT(FILE *file, int alg)
{
  Process rejectedProcesses[10000];
  char Algorithm[2][10] = {"FCFS", "PR"};
  int rejectedCount = 0;
  char c[100];
  int startTime = 0;
  int endTime;
  char plant[3][10] = {"PLANT_X", "PLANT_Y", "PLANT_Z"};
  for (int i = 0; i < processesCount; i++)
  {
    if (processes[i].accepted == 0)
    {
      rejectedProcesses[i] = processes[i];
    }
  }

  fprintf(file, "Algorithm used: %s\n", Algorithm[alg]);
  fprintf(file, "There are %d Orders ACCEPTED.", dayCount[0] + dayCount[1] + dayCount[2]);
  fprintf(file, " Details are as follows: \n");
  fprintf(file, "ORDER NUMBER   START        END         DAYS    QUANTITY    PLANT\n");
  for (int i = 0; i < 3; i++)
  {
    memcpy(c, day[i][0].Product.orderNumber, sizeof(c));
    for (int j = 0; j < dayCount[i]; j++)
    {
      int check = memcmp(c, day[i][j].Product.orderNumber, sizeof(c));
      if (check == 0)
      {
      }
      else
      {
        memcpy(c, day[i][j].Product.orderNumber, sizeof(c));
        endTime = j - 1;
        int days = endTime - startTime + 1;
        fprintf(file, "%s %s %s %d %d %s\n", day[i][j].Product.orderNumber, intToTime(startTime), intToTime(endTime), days, day[i][j].producedQuantity, plant[i]);
      }
    }
    fprintf(file, "%s %s %s %d %d %s\n",
            day[0][0].Product.orderNumber, intToTime(startTime), intToTime(endTime),
            2, day[0][0].producedQuantity, plant[i]);
  }
  fprintf(file, "- END -\n");
  fprintf(file, "There are %d Orders REJECTED.", rejectedCount);
  fprintf(file, " Details are as follows: ");
  fprintf(file, "ORDER NUMBER   PRODUCT NAME Due Date QUANTITY\n");
  for (int i = 0; i < rejectedCount; i++)
  {
    fprintf(file, "%s %c %s %d\n", rejectedProcesses[i].orderNumber, 'A' + rejectedProcesses[i].products, intToTime(rejectedProcesses[i].dueDate), rejectedProcesses[i].quantity);
  }
  fprintf(file, "- END -\n");

  // here for parent to analyse.
  // here for parent to analyse.
  int parent_to_child[3][2];
  int child_to_parent[3][2];
  printf("%s\n", "***PERFORMANCE");
  for (int i = 0; i < 3; i++)
  {
    pid_t pid = fork();
    close(parent_to_child[i][1]); // Close write end of parent_to_child pipe
    close(child_to_parent[i][0]); // Close read end of child_to_parent pipe
    if (pid < 0)
    {
      printf("Fork failed\n");
      exit(1);
    }
    else if (pid == 0) // Child process
    {
      int start[1];
      read(parent_to_child[i][0], start, sizeof(int));
      char a[3] = {'X', 'Y', 'Z'};
      fprintf(file, "Plant_%c:\n", a[i]);
      memcpy(c, day[i][0].Product.orderNumber, sizeof(c));
      for (int j = 0; j < dayCount[i]; j++)
      {
        int check = memcmp(c, day[i][j].Product.orderNumber, sizeof(c));
        if (check == 0)
        {
        }
        else
        {
          memcpy(c, day[i][j].Product.orderNumber, sizeof(c));
          endTime = j - 1;
          int days = endTime - startTime;
          fprintf(file, "%s %s %s %d %d %s\n", day[i][j].Product.orderNumber, intToTime(startTime), intToTime(endTime), days, day[i][j].producedQuantity, plant[i]);
        }
      }
      write(child_to_parent[i][1], start, sizeof(int));
      exit(0);
    }
  }

  for (int i = 0; i < 3; i++)
  {
    int start[1];
    write(parent_to_child[i][1], start, sizeof(int));

    int end[1];
    read(child_to_parent[i][0], end, sizeof(int));
  }
}
