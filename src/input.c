#include "input.h"

// #define _DEBUG_
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[10000];
int dayCount;
int endPeiod;
time_t startPeiod;

int main(){
}
#endif


void addPEIOD(char** command, int len){
  if (len != 3) {
    errorUsage(0);
    return;
  }

  struct tm tmt;
  if (strlen(command[1]) != 10
      || !strptime(command[1], "%Y-%m-%d", &tmt)){
    printf("addPEIOD: %s: Invalid date format.\n", command[1]);
    return;
  }
  if (strlen(command[2]) != 10
      || !strptime(command[2], "%Y-%m-%d", &tmt)){
    printf("addPEIOD: %s: Invalid date format.\n", command[2]);
    return;
  }
  initTime(command[1]);
  endPeiod = timeToInt(command[2]);
}

int addORDER(char** command, int len){
  //addORDER P0002 2024-06-13 3000 Product_D
  if (len != 5) {
    errorUsage(1);
    return -1;
  }

  memcpy(processes[processesCount].orderNumber, command[1], sizeof(char)*strlen(command[1]));

  struct tm tmt;
  if (strlen(command[2]) != 10
      || !strptime(command[2], "%Y-%m-%d", &tmt)){
    printf("addORDER: %s: Invalid date format.\n", command[2]);
    return -1;
  }
  processes[processesCount].dueDate = timeToInt(command[2]);

  if (!~sscanf(command[3], "%d", &processes[processesCount].quantity)) {
    printf("addORDER: %s: Invalid quantity format.\n", command[3]);
    return -1;
  }

  char str[10];
  int p;
  if (strlen(command[4]) != 9
      || streq(memcpy(str, command[4], sizeof(char) * 7), "Product_")
      || (p = command[4][8] - 'A') >= 9
      || (p < 0)) {
    printf("addORDER: %s: Invalid products.\n", command[4]);
    return -1;
  }
  processes[processesCount].products = p;
  processes[processesCount].categorie = p/3;

  processesCount ++;
  return 0;
}

void addBATCH(char** c, int len) {
  if(len != 2) return;
  FILE* f = fopen(c[1], "r");
  if (!f) {
    printf("addBATCH: %s: Incalid files.\n", c[1]);
  }

  while (1){
    char str[100];
    char* result = fgets(str, 100, f);
    if (!result) return;
    int commandLen;
    char** command = genCommand(str, &commandLen);
    if(!streq(command[0], "addORDER")){
      printf("addBATCH: Invalid command in files.\n");
      continue;
    }
    addORDER(command, commandLen);
  }
}
