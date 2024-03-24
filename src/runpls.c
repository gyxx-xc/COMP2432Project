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
  processes[processesCount ++] = (Process) {"P0000", 3, 1, 300, 1};
  processes[processesCount ++] = (Process) {"P0001", 4, 1, 200, 1};
  processes[processesCount ++] = (Process) {"P0002", 5, 1, 100, 2};
  processes[processesCount ++] = (Process) {"P0003", 6, 1, 500, 0};
  processes[processesCount ++] = (Process) {"P0004", 7, 1, 1000, 2};
  processes[processesCount ++] = (Process) {"P0005", 2, 1, 2000, 0};
  processes[processesCount ++] = (Process) {"P0006", 3, 1, 120, 1};
  processes[processesCount ++] = (Process) {"P0007", 1, 1, 2332, 1};
  processes[processesCount ++] = (Process) {"P0008", 5, 1, 413342, 2};
  processes[processesCount ++] = (Process) {"P0009", 6, 1, 1231, 0};
  processes[processesCount ++] = (Process) {"P0010", 7, 1, 235230, 2};
  processes[processesCount ++] = (Process) {"P0011", 8, 1, 1230, 0};
  runPLS(1);
}
#endif


void FCFS(){
  //最基础的，判断订单的时间，先来先服务(不抢断，对于单个厂来说，来了就一口气给订单干完)
  //注意判断订单的时间是否在"开工时间"内，"看情况"拒单
  int i,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod; //X工厂剩余可开工日期，产能300/天
  int YDays=endPeiod; //Y工厂剩余可开工日期，产能400/天
  int ZDays=endPeiod; //Z工厂剩余可开工日期，产能500/天
  int XYZStatus[3]={0,0,0}; // X(0) Y(1) Z(2) 三厂的状态，0表示可以接单，便把生产天数写到对应的状态上
  for(i=0;i<processesCount;i++){
    int productivity=0;
    for(k=0;k<3;k++){
      if (XYZStatus[k]==0){
        if(k==0){ //X工厂当前闲置，可"尝试"接单
          //X工厂产能=300
          productivity=300;
          int needDays=processes[i].quantity/productivity;
          if(needDays<=XDays){
            XYZStatus[k]=needDays;
            XDays-=needDays;
            processes[i].accepted=1;
            day[k][dayCount[k]].Product=processes[i];
            day[k][dayCount[k]].producedQuantity=processes[i].quantity;
            
          }else{
            processes[i].accepted=0; //生产天数需求 大于 X厂剩余可开工时间-->拒绝接单
          }

        }else if(k==1){ //Y工厂当前闲置，可"尝试"接单
          //Y工厂产能=400
          productivity=400;
          int needDays=processes[i].quantity/productivity;
          if(needDays<=YDays){
            XYZStatus[k]=needDays;
            YDays-=needDays;
            processes[i].accepted=1;
            day[k][dayCount[k]].Product=processes[i];
            day[k][dayCount[k]].producedQuantity=processes[i].quantity;
          }else{
            processes[i].accepted=0; //生产天数需求 大于 Y厂剩余可开工时间-->拒绝接单
          }

        }else if(k==2){ //Z工厂当前闲置，可"尝试"接单
          //Z工厂产能=500
          productivity=500;
          int needDays=processes[i].quantity/productivity;
          if(needDays<=ZDays){
            XYZStatus[k]=needDays;
            ZDays-=needDays;
            processes[i].accepted=1;
            day[k][dayCount[k]].Product=processes[i];
            day[k][dayCount[k]].producedQuantity=processes[i].quantity;
          }else{
            processes[i].accepted=0; //生产天数需求 大于 Z厂剩余可开工时间-->拒绝接单
          }

        }
      }
      
    }
    // day[dayCount].Product=processes[i];
    // day[dayCount].producedQuantity=productivity;
    // dayCount++;
    for(k=0;k<3;k++){//开工，生产剩余天数-1;
      if(XYZStatus[k]!=0){
        XYZStatus[k]-=1;
      }
    }


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
 Process rawDay[10000];
 int i;

 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 0){
    rawDay[dayCounting++] = processes[i];
  }
 }

 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 1){
    rawDay[dayCounting++] = processes[i];
  }
 }
  
 for(i=0;i<processesCount;i++){
  if (processes[i].categorie == 2){
    rawDay[dayCounting++] = processes[i];
  }
 }

 int day1row=0,day2row=0,day3row=0;

 // 存入二维数组

 for (i=0;i<dayCounting;i++){
  if (rawDay[i].quantity<=300){
    day[0][day1row++].Product = rawDay[i];
  } else if (rawDay[i].quantity>300 && rawDay[i].quantity <= 500){
    day[1][day2row++].Product = rawDay[i];
  } else {
    day[2][day3row++].Product = rawDay[i];
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
