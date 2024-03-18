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

int command(char* str);
int commandAlg(char* str);
int hasFile(char* str);

int timeToInt(char* str);
char* intToTime(int i);
