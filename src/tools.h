#ifndef TOOLS_H
#define TOOLS_H

#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct proc {
  char orderNumber[100];
  int dueDate;
  int quantity;
  int products;
  int categorie;
  int accepted; // modify by runpls
} Process;


typedef struct dayArrange {
  Process Product;
  int producedQuantity;
} DayArrange;

extern Process processes[10000];
extern int processesCount;
extern DayArrange day[10000];
extern int dayCount;
extern time_t startPeiod;
extern int endPeiod;

int streq(const char* a, const char* b);

void printMenu();
void errorCommand(char* str);
void errorAlg(char* str);
void errorUsage(int c);

char** genCommand(char* str, int* len);

int checkCommand(char* str);
int commandAlg(char* str);
int checkRunUsage(char** command, int len);

// the int is the day since startpeiod
// startpeiod is 0, and so on
// you can call initTime to set startpeiod
void initTime(char* startTime);
int timeToInt(char* str);
char* intToTime(int i);

#endif
