#include "tools.h"

int command(char* str) {
  return 1;
}

int commandAlg(char* str) {
  return 1;
}

int hasFile(char* str) {
  return 0;
}

int timeToInt(char* str) {
  return 0;
}

char* intToTime(int i) {
  char* str = malloc(10*sizeof(char));
  str[0] = 'a';
  str[1] = 0;
  return str;
}
