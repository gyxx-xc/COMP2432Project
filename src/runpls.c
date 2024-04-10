#include "runpls.h"

// seperate the alg from here
// after decided which alg you are going to use, write it in readme
// read the process from `processes`(globle)  从processs[]中读入订单数据，然后看“怎么插入 day[]这个数组中”
// and write the result into `day`(globle) day[]这个数组就会用来存取我们的“排好序的”订单数据，processesCount 和 dayCount分别表示两个数组的大小

/*以下为"订单 (Process)"的结构体参考
  typedef struct proc {
  char orderNumber[100]; //订单号
  int dueDate; //持续时间
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

//#define _DEBUG_ // to debug uncomment this line and run `gcc runpls.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[3][10000];// 对应X0 Y1 Z2 工厂的接收订单数组[]
int dayCount[3]; //对应XYZ的接收订单Count
time_t startPeiod;
int endPeiod;

int main(){
  // set process...
  // call algrothm
  // print some debug output
  initTime("2022-01-01"); //
  endPeiod = timeToInt("2022-01-30");
  //"订单号" 需要生产天数 需要生产数量 种类 是否接受%
  processes[processesCount ++] = (Process) {"P1000", 3, 1000, 0, 1}; //B (3)
  processes[processesCount ++] = (Process) {"P1001", 3, 700, 2, 1};
  processes[processesCount ++] = (Process) {"P1002", 3, 1200, 1, 2};
  processes[processesCount ++] = (Process) {"P1003", 6, 1300, 2, 0};
  processes[processesCount ++] = (Process) {"P1004", 3, 1400, 1, 2};
  processes[processesCount ++] = (Process) {"P1005", 3, 1500, 1, 0};
  processes[processesCount ++] = (Process) {"P1006", 4, 2000, 0, 1};
  processes[processesCount ++] = (Process) {"P1007", 4, 2200, 2, 1};
  processes[processesCount ++] = (Process) {"P1008", 4, 2400, 2, 2};
  processes[processesCount ++] = (Process) {"P1009", 4, 2600, 1, 0};
  processes[processesCount ++] = (Process) {"P1010", 4, 2800, 0, 2};
  processes[processesCount ++] = (Process) {"P1011", 6, 3000, 0, 2};
  runPLS(0);
  int i,j;
  // for (m=0;m<dayCount;m++){
  //   printf("订单号:%s 截止日期:%d 数量:%d 种类:%d 是否接受%d\n",
  //   day[].Product.orderNumber,
  //   day[m].Product.dueDate,
  //   day[m].Product.quantity,
  //   day[m].Product.categorie,
  //   day[m].Product.accepted);
  // }
  //订单号 需要生产天数 需要生产数量 种类 是否接受%
  processes[processesCount ++] = (Process) {"P0000", 3, 1000, 0, 1};
  processes[processesCount ++] = (Process) {"P0001", 4, 200, 2, 1};
  processes[processesCount ++] = (Process) {"P0002", 5, 300, 1, 2};
  processes[processesCount ++] = (Process) {"P0003", 6, 400, 2, 0};
  processes[processesCount ++] = (Process) {"P0004", 7, 1400, 1, 2};
  processes[processesCount ++] = (Process) {"P0005", 2, 2400, 1, 0};
  processes[processesCount ++] = (Process) {"P0006", 3, 500, 0, 1};
  processes[processesCount ++] = (Process) {"P0007", 1, 600, 2, 1};
  processes[processesCount ++] = (Process) {"P0008", 5, 900, 2, 2};
  processes[processesCount ++] = (Process) {"P0009", 6, 2000, 1, 0};
  processes[processesCount ++] = (Process) {"P0010", 7, 1230, 0, 2};
  processes[processesCount ++] = (Process) {"P0011", 8, 3, 0, 0};
  // runPLS(1);
  int m;
  printf("工厂x\n");
  for (m=0;m<dayCount[0];m++){
    printf("订单号:%s 截止绝对日期:%d 当日产量:%d 种类:%d 是否接受%d\n",
           day[0][m].Product.orderNumber,
           day[0][m].Product.dueDate,
           day[0][m].producedQuantity,
           day[0][m].Product.categorie,
           day[0][m].Product.accepted);
  }
  printf("工厂y\n");
  for (m=0;m<dayCount[1];m++){
    printf("订单号:%s 截止绝对日期:%d 当日产量:%d 种类:%d 是否接受%d\n",
           day[1][m].Product.orderNumber,
           day[1][m].Product.dueDate,
           day[1][m].producedQuantity,
           day[1][m].Product.categorie,
           day[1][m].Product.accepted);
  }
  printf("工厂z\n");
  for (m=0;m<dayCount[2];m++){
    printf("订单号:%s 截止绝对日期:%d 当日产量:%d 种类:%d 是否接受%d\n",
           day[2][m].Product.orderNumber,
           day[2][m].Product.dueDate,
           day[2][m].producedQuantity,
           day[2][m].Product.categorie,
           day[2][m].Product.accepted);
  }

  // for(i=0;i<3;i++){
  //   for(j=0;j<dayCount[i];j++){
  //     printf("订单号:%s 要求生产天数:%d 数量:%d 种类:%d 是否接受%d\n",
  //     day[i][j].Product.orderNumber,
  //     day[i][j].Product.dueDate,
  //     day[i][j].Product.quantity,
  //     day[i][j].Product.categorie,
  //     day[i][j].Product.accepted);
  //   }

  // }
}
#endif


void FCFS(){
  //最基础的，判断订单的时间，先来先服务(不抢断，对于单个厂来说，来了就一口气给订单干完)
  //注意判断订单的时间是否在"开工时间"内，"看情况"拒单
  int i,j,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod; //X工厂剩余可开工日期，产能300/天
  int YDays=endPeiod; //Y工厂剩余可开工日期，产能400/天
  int ZDays=endPeiod; //Z工厂剩余可开工日期，产能500/天
  int currentDay=0;

  int XYZStatus[3]={0,0,0}; // X(0) Y(1) Z(2) 三厂的状态，0表示可以接单，便把生产天数写到对应的状态上
  for(i=0;i<processesCount;i++){
    int productivity=0;
    for(k=0;k<3;k++){
      while(XYZStatus[0]!=0&&XYZStatus[1]!=0&&XYZStatus[2]!=0){
        XYZStatus[0]--;
        XYZStatus[1]--;
        XYZStatus[2]--;
        currentDay++;
      }
      if (XYZStatus[k]==0){
        if(k==0){ //X工厂当前闲置，可"尝试"接单
          //X工厂产能=300
          productivity=300;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){//实际天数>需求天数，不切实际
            processes[i].accepted=0;
          }
          else if(processes[i].dueDate-currentDay>=needDays&&needDays<=XDays){
            XYZStatus[k]=processes[i].dueDate-currentDay;
            XDays-=needDays;
            processes[i].accepted=1;
            for(j=0;j<needDays;j++){

              day[k][dayCount[k]].Product=processes[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }

            break;

          }else{
            processes[i].accepted=0; //生产天数需求 大于 X厂剩余可开工时间-->拒绝接单
          }

        }else if(k==1){ //Y工厂当前闲置，可"尝试"接单
          //Y工厂产能=400
          productivity=400;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){
            processes[i].accepted=0;
          }
          if(processes[i].dueDate-currentDay>=needDays&&needDays<=YDays){
            XYZStatus[k]=processes[i].dueDate-currentDay;
            YDays-=needDays;
            processes[i].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=processes[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[i].accepted=0;  //生产天数需求 大于 Y厂剩余可开工时间-->拒绝接单
          }

        }else if(k==2){ //Z工厂当前闲置，可"尝试"接单
          //Z工厂产能=500
          productivity=500;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){
            processes[i].accepted=0;
          }
          else if(processes[i].dueDate-currentDay>=needDays&&needDays<=ZDays){
            XYZStatus[k]=processes[i].dueDate-currentDay;
            ZDays-=needDays;
            processes[i].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=processes[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[i].accepted=0; //生产天数需求 大于 Z厂剩余可开工时间-->拒绝接单
          }

        }
      }

    }
    // day[dayCount].Product=processes[i];
    // day[dayCount].producedQuantity=productivity;
    // dayCount++;

    // for(k=0;k<3;k++){//开工，生产剩余天数-1;
    //   if(XYZStatus[k]!=0){
    //     XYZStatus[k]-=1;
    //   }
    // }


  }
}



void priorityScheduling() {
  //查看传入订单的"种类"，共分为三类
  /*
    Product_A, B and C 属于 Category_1
    Product_D, E and F 属于 Category_2
    Product_G, H and I 属于 Category_3
    其中，优先级Category_1 > Category_2 > Category_3
  */
  int dayCounting = 0;
  Process* rawDay = (Process*)malloc(sizeof(Process)*processesCount);
  int* acceptedIndex = (int*)malloc(sizeof(int)*processesCount);
  int i;

  for(i=0;i<processesCount;i++){
    if (processes[i].categorie == 0){
      acceptedIndex[dayCounting] = i;
      rawDay[dayCounting++] = processes[i];

    }
  }

  for(i=0;i<processesCount;i++){ //400
    if (processes[i].categorie == 1){
      acceptedIndex[dayCounting] = i;
      rawDay[dayCounting++] = processes[i];
    }
  }

  for(i=0;i<processesCount;i++){
    if (processes[i].categorie == 2){
      acceptedIndex[dayCounting] = i;
      rawDay[dayCounting++] = processes[i];
    }
  }

  // 存入二维数组
  // the above is good, the rest is wrong,
  // don't need to change, there's a simple way
  // do the FCFS toghter and copy it
  // it is the same for the rest
  int j,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod; //X工厂剩余可开工日期，产能300/天
  int YDays=endPeiod; //Y工厂剩余可开工日期，产能400/天
  int ZDays=endPeiod; //Z工厂剩余可开工日期，产能500/天
  int currentDay=0;

  int XYZStatus[3]={0,0,0}; // X(0) Y(1) Z(2) 三厂的状态，0表示可以接单，便把生产天数写到对应的状态上
  for(i=0;i<processesCount;i++){
    int productivity=0;
    for(k=0;k<3;k++){
      while(XYZStatus[0]!=0&&XYZStatus[1]!=0&&XYZStatus[2]!=0){
        XYZStatus[0]--;
        XYZStatus[1]--;
        XYZStatus[2]--;
        currentDay++;
      }
      if (XYZStatus[k]==0){
        if(k==0){ //X工厂当前闲置，可"尝试"接单
          //X工厂产能=300
          productivity=300;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){//实际天数>需求天数，不切实际
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=XDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            XDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){

              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }

            break;

          }else{
            processes[acceptedIndex[i]].accepted=0; //生产天数需求 大于 X厂剩余可开工时间-->拒绝接单
          }

        }else if(k==1){ //Y工厂当前闲置，可"尝试"接单
          //Y工厂产能=400
          productivity=400;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=YDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            YDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[acceptedIndex[i]].accepted=0;  //生产天数需求 大于 Y厂剩余可开工时间-->拒绝接单
          }

        }else if(k==2){ //Z工厂当前闲置，可"尝试"接单
          //Z工厂产能=500
          productivity=500;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=ZDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            ZDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[acceptedIndex[i]].accepted=0; //生产天数需求 大于 Z厂剩余可开工时间-->拒绝接单
          }

        }
      }
    }
  }
}

// closest due-date first
void CDF() {
  int* mark = (int*)malloc(sizeof(int)*processesCount);
  int dayCounting = 0;
  Process* rawDay = (Process*)malloc(sizeof(Process)*processesCount);
  int* acceptedIndex = (int*)malloc(sizeof(int)*processesCount);
  int i;
  memset(mark, 0, sizeof(int)*processesCount);
  for (i = 0; i < processesCount; i++) {
    int min = 0x7fffffff;
    int minIndex = -1;
    for (int j = 0; j < processesCount; j++) {
      if (mark[j] == 0 && processes[j].dueDate < min) {
        min = processes[j].dueDate;
        minIndex = j;
      }
    }
    mark[minIndex] = 1;
    acceptedIndex[dayCounting] = minIndex;
    rawDay[dayCounting++] = processes[minIndex];
  }

  int j,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod; //X工厂剩余可开工日期，产能300/天
  int YDays=endPeiod; //Y工厂剩余可开工日期，产能400/天
  int ZDays=endPeiod; //Z工厂剩余可开工日期，产能500/天
  int currentDay=0;

  int XYZStatus[3]={0,0,0}; // X(0) Y(1) Z(2) 三厂的状态，0表示可以接单，便把生产天数写到对应的状态上
  for(i=0;i<processesCount;i++){
    int productivity=0;
    for(k=0;k<3;k++){
      while(XYZStatus[0]!=0&&XYZStatus[1]!=0&&XYZStatus[2]!=0){
        XYZStatus[0]--;
        XYZStatus[1]--;
        XYZStatus[2]--;
        currentDay++;
      }
      if (XYZStatus[k]==0){
        if(k==0){ //X工厂当前闲置，可"尝试"接单
          //X工厂产能=300
          productivity=300;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){//实际天数>需求天数，不切实际
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=XDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            XDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){

              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }

            break;

          }else{
            processes[acceptedIndex[i]].accepted=0; //生产天数需求 大于 X厂剩余可开工时间-->拒绝接单
          }

        }else if(k==1){ //Y工厂当前闲置，可"尝试"接单
          //Y工厂产能=400
          productivity=400;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=YDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            YDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[acceptedIndex[i]].accepted=0;  //生产天数需求 大于 Y厂剩余可开工时间-->拒绝接单
          }

        }else if(k==2){ //Z工厂当前闲置，可"尝试"接单
          //Z工厂产能=500
          productivity=500;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=ZDays){
            XYZStatus[k]=rawDay[i].dueDate-currentDay;
            ZDays-=needDays;
            processes[acceptedIndex[i]].accepted=1;
            for(j=0;j<needDays;j++){
              day[k][dayCount[k]].Product=rawDay[i];
              day[k][dayCount[k]].producedQuantity=productivity;
              if(jugde && j==needDays-1){
                day[k][dayCount[k]].producedQuantity=jugde;
              }
              dayCount[k]++;
            }
            break;

          }else{
            processes[acceptedIndex[i]].accepted=0; //生产天数需求 大于 Z厂剩余可开工时间-->拒绝接单
          }

        }
      }
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
  case 2:
    CDF();
    break;
  }
}
