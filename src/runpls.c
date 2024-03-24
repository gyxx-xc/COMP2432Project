#include "runpls.h"

// seperate the alg from here
// after decided which alg you are going to use, write it in readme
// read the process from `processes`(globle)  从processs[]中读入订单数据，然后看“怎么插入 day[]这个数组中”
// and write the result into `day`(globle) day[]这个数组就会用来存取我们的“排好序的”订单数据，processesCount 和 dayCount分别表示两个数组的大小

/*以下为"订单 (Process)"的结构体参考
typedef struct proc {
  char orderNumber[100]; //订单号
  int durDate; //持续时间
  int quantity; //生产数量
  int categorie; //(0,1,2) -->第三优先 ; (3,4,5)-->第二优先 ; (6,7,8)-->第三优先
  int accepted; // modify by runpls
  //0表示拒绝，1表示接受
} Process;

注意以"天"为单位，每天的订单都会被记录在day[]中
typedef struct dayArrange {
  Process Product;
  int producedQuantity;
} DayArrange;

global varible
Process processes[10000];
DayArrange day[10000];
int endPeiod;
*/

//待解决问题: 如何获得当日的各种杂七杂八订单，以及对他们进行"in place"的排序，事后又该如何记录

#define _DEBUG_ // to debug uncomment this line and run `gcc runpls.c`
#ifdef _DEBUG_
Process processes[10000]; //要处理的对象
int processesCount;
DayArrange day[10000];
int dayCount;
int endPeiod;
time_t startPeiod;

int main(){
  // set process...
  // call algrothm
  // print some debug output
  initTime("2022-01-01");
  endPeiod = timeToInt("2022-01-30");
  processes[processesCount ++] = (Process) {"P0000", 3, 1, 0, 1};
  processes[processesCount ++] = (Process) {"P0001", 4, 1, 2, 1};
  processes[processesCount ++] = (Process) {"P0002", 5, 1, 1, 2};
  processes[processesCount ++] = (Process) {"P0003", 6, 1, 2, 0};
  processes[processesCount ++] = (Process) {"P0004", 7, 1, 1, 2};
  processes[processesCount ++] = (Process) {"P0005", 2, 1, 1, 0};
  processes[processesCount ++] = (Process) {"P0006", 3, 1, 0, 1};
  processes[processesCount ++] = (Process) {"P0007", 1, 1, 2, 1};
  processes[processesCount ++] = (Process) {"P0008", 5, 1, 2, 2};
  processes[processesCount ++] = (Process) {"P0009", 6, 1, 1, 0};
  processes[processesCount ++] = (Process) {"P0010", 7, 1, 0, 2};
  processes[processesCount ++] = (Process) {"P0011", 8, 1, 0, 0};
  runPLS(1);
  int m;
  for (m=0;m<dayCount;m++){
    printf("订单号:%s 截止日期:%d 数量:%d 种类:%d 是否接受%d\n",
    day[m].Product.orderNumber,
    day[m].Product.dueDate,
    day[m].Product.quantity,
    day[m].Product.categorie,
    day[m].Product.accepted);
  }
}
#endif


void FCFS(){
  //最基础的，判断订单的时间，先来先服务(不抢断，来了就一口气给订单干完)
  //注意判断订单的时间是否在"开工时间"内，看情况拒单
  

}

void priorityScheduling() {
  //查看传入订单的"种类"，共分为三类
  /*
  Product_A, B and C 属于 Category_1
  Product_D, E and F 属于 Category_2
  Product_G, H and I 属于 Category_3
  其中，优先级Category_1 > Category_2 > Category_3
  */
 dayCount = 0;

 int i;

 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 0){
    day[dayCount++].Product = processes[i];
  }
 }

 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 1){
    day[dayCount++].Product = processes[i];
  }
 }

 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 2){
    day[dayCount++].Product = processes[i];
  }
 }
}
void runPLS(int alg) {
  switch (alg) {
    //注: int alg 已经在上游被处理好了，我们这里只需要指定 int 和 不同算法实现的函数() 进行映射即可
    //如 0-->FCFS, 1-->SJF, 2-->RR, 3-->HRRN, 4-->SRTN 等等等等
  case 0:
    FCFS();
    break;
  case 1:
    priorityScheduling();
    break;
  }
}
