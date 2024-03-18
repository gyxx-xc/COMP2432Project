#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>

typedef struct proc {
  char orderNumber[100];
  int durDate;
  int quantity;
  int categorie;
  int priority;
} Process;


typedef struct dayArrange {
  Process Product;
  int producedQuantity;
} DayArrange;

extern Process processes[10000];
extern DayArrange day[10000];
extern int peiod[2];

void printMenu();

int command(char* str);
int commandAlg(char* str);
int hasFile(char* str);

int timeToInt(char* str);
char* intToTime(int i);

#endif
