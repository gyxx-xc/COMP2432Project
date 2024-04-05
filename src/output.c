#include "output.h"
#include <unistd.h>
#include <sys/wait.h>

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
        (Process){"", i, 100 * i ^ 3, i % 9, 0, 1},
        100};
    memcpy(day[i % 3][dayCount[i % 3] - 1].Product.orderNumber, a, sizeof(a));
    a[4]++;
  }

  printf("%d\n", day[1][0].Product.products);

  printREPORT(stdout, 0);
}
#endif

// Function to write `usingdays` and `ToTalproducedQuantity` to the pipe
void writeToPipe(int pipe_fd, int *usingdays, int ToTalproducedQuantity[])
{
  write(pipe_fd, usingdays, sizeof(int) * 3);
  write(pipe_fd, ToTalproducedQuantity, sizeof(int) * 3);
}

// Function to read `usingdays` and `ToTalproducedQuantity` from the pipe
void readFromPipe(int pipe_fd, int *usingdays, int ToTalproducedQuantity[])
{
  read(pipe_fd, usingdays, sizeof(int) * 3);
  read(pipe_fd, ToTalproducedQuantity, sizeof(int) * 3);
}

// child process
// read the `day` from pipe here
// the function intToTime in `tools.h` may useful
void printREPORT(FILE *file, int alg)
{
  fprintf(file, "***PLS Schedule Analysis Report***\n");
  fprintf(file, "\n");
  Process rejectedProcesses[10000];
  char Algorithm[2][10] = {"FCFS", "PR"};
  int rejectedCount = 0;
  char c[100];
  int startTime = 0;
  int endTime;
  char plant[3][10] = {"PLANT_X", "PLANT_Y", "PLANT_Z"};
  int quantity = 0;
  int usingdays[3] = {0};             // Initialize usingdays
  int ToTalproducedQuantity[3] = {0}; // Initialize ToTalproducedQuantity
  int pipe_fd[2];                     // Pipe file descriptors

  // Create pipe
  if (pipe(pipe_fd) == -1)
  {
    perror("Pipe failed");
    exit(1);
  }

  for (int i = 0; i < processesCount; i++)
  {
    if (processes[i].accepted == 0)
    {
      rejectedProcesses[i] = processes[i];
    }
  }

  fprintf(file, "Algorithm used: %s\n", Algorithm[alg]);
  fprintf(file, "\n");
  fprintf(file, "There are %d Orders ACCEPTED.", dayCount[0] + dayCount[1] + dayCount[2]);
  fprintf(file, " Details are as follows: \n");
  fprintf(file, "ORDER NUMBER\tSTART\t\tEND\t\tDAYS\tQUANTITY\tPLANT\n");
  for (int i = 0; i < 3; i++)
  {
    memcpy(c, day[i][0].Product.orderNumber, sizeof(c));
    for (int i = 0; i < 3; i++)
    {
      memcpy(c, day[i][0].Product.orderNumber, sizeof(c));
      startTime = 0;
      if (dayCount[i] == 0)
      {
        continue;
      }
      for (int j = 0; j < dayCount[i]; j++)
      {
        int check = memcmp(c, day[i][j].Product.orderNumber, sizeof(c));
        if (check == 0)
        {
          quantity = quantity + day[i][j - 1].producedQuantity;
        }
        else
        {
          memcpy(c, day[i][j].Product.orderNumber, sizeof(c));
          endTime = j - 1;
          int days = endTime - startTime + 1;
          fprintf(file, "%s\t\t%s\t%s\t%d\t%d\t\t%s\n",
                  day[i][j - 1].Product.orderNumber,
                  intToTime(startTime), intToTime(endTime),
                  days, quantity + day[i][j - 1].producedQuantity, plant[i]);
          startTime = j;
          quantity = 0;
        }
      }
      endTime = dayCount[i] - 1;
      int days = endTime - startTime + 1;
      fprintf(file, "%s\t\t%s\t%s\t%d\t%d\t\t%s\n",
              day[i][dayCount[i] - 1].Product.orderNumber,
              intToTime(startTime), intToTime(endTime),
              days, day[i][dayCount[i] - 1].producedQuantity, plant[i]);
    }
    fprintf(file, "\t- END -\n");
    fprintf(file, "\n");
    fprintf(file, "There are %d Orders REJECTED.", rejectedCount);
    fprintf(file, " Details are as follows: ");
    fprintf(file, "\n");
    fprintf(file, "ORDER NUMBER\tPRODUCT\tNAME\tDue Date\tQUANTITY\n");
    for (int i = 0; i < rejectedCount; i++)
    {
      fprintf(file, "%s\t\tProduct_%c\t%s\t%d\n", rejectedProcesses[i].orderNumber, 'A' + rejectedProcesses[i].products, intToTime(rejectedProcesses[i].dueDate), rejectedProcesses[i].quantity);
    }
    fprintf(file, "\t- END -\n");
    fprintf(file, "\n");

    // here for parent to analyse.
    // here for parent to analyse.
    int parent_pid = getpid();
    int prev_pid = parent_pid;
    int child_pid[3];
    for (int i = 0; i < 3; i++)
    {
      child_pid[i] = fork();

      if (child_pid[i] < 0)
      {
        fprintf(stderr, "Fork failed\n");
        exit(1);
      }
      else if (child_pid[i] == 0)
      { // child process
        char b[3] = "XYZ";
        fprintf(file, "Plant_%c\n", b[i]);
        fprintf(file, "Date\t\tProduct Name\tOrder Number\tQuantity(Produced)\tDueDate\n");
        for (int j = 0; j < dayCount[i]; j++)
        {
          if (day[i][j].producedQuantity == 0)
          {
            fprintf(file, "%s NA  \n",
                    intToTime(j));
          }
          else
          {
            fprintf(file, "%s\tProduct_%c\t\t%s\t\t%d\t\t\t%s\n",
                    intToTime(j),
                    'A' + day[i][j].Product.products,
                    day[i][j].Product.orderNumber,
                    day[i][j].producedQuantity, intToTime(day[i][j].Product.dueDate));
            usingdays[i]++;
            ToTalproducedQuantity[i] += day[i][j].producedQuantity; // Increment ToTalproducedQuantity
          }
        }
        writeToPipe(pipe_fd[1], usingdays, ToTalproducedQuantity); // Write usingdays and ToTalproducedQuantity to the pipe
        exit(0);
      }
      else
      {
        waitpid(child_pid[i], NULL, 0);
      }
    }

    // Parent process
    waitpid(prev_pid, NULL, 0);

    // Read usingdays and ToTalproducedQuantity from each child process

    fprintf(file, "%s\n", "***PERFORMANCE");
    int ALLToTalproducedQuantity = 0;
    int AllTotal = 0;

    for (int i = 0; i < 3; i++)
    {

      fprintf(file, "Plant %c:\n", 'X' + i);
      readFromPipe(pipe_fd[0], usingdays, ToTalproducedQuantity);
      fprintf(file, "Using days: %d\n", usingdays[i]);
      fprintf(file, "Total produced quantity: %d\n", ToTalproducedQuantity[i]);
      int total = dayCount[i] * (300 + 100 * i);
      float Utilization = ToTalproducedQuantity[i] * 100 / total;
      fprintf(file, "Utilization of the plant: %.1f\%\n", Utilization);
      ALLToTalproducedQuantity = ALLToTalproducedQuantity + ToTalproducedQuantity[i];
      AllTotal += total;
    }
    float Utilization = ALLToTalproducedQuantity * 100 / AllTotal;
    fprintf(file, "Utilization of All: %.1f\%\n", Utilization);
    return;
  }
}