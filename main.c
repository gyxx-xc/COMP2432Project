typedef struct process {
  char orderNumber[100];
  int durDate;
  int quantity;
  int categorie;
  int priority;
} Process;

int main() {
  while(1){
    char str[100];
    getline(&str);
    switch(command(str)) {
    case 0:
      addPEIOD();
      break;
    case 1:
      addORDER();
      break;
    case 2:
      addBATCH();
      break;
    case 3:
      runPLS();
      printREPORT();
      break;
    case 4:
      exitPLS();
      break;
    }
  }
}
