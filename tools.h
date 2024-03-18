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

Process processes[10000];
DayArrange day[10000];
int peiod[2];

int command(char* str);
int commandAlg(char* str);
int hasFile(char* str);

int timeToInt(char* str);
char* intToTime(int i);
