#ifndef TOOLS_H
#define TOOLS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

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
extern time_t startPeiod;
extern int endPeiod;

void printMenu();
void errorCommand(char* str);
void errorAlg(char* str);

int command(char* str);
int commandAlg(char* str);
int hasFile(char* str);

// the int is the day since startpeiod
// startpeiod is 0, and so on
int timeToInt(char* str);
char* intToTime(int i);

#endif
