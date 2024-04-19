#include "runpls.h"

// seperate the alg from here
// after decided which alg you are going to use, write it in readme
// read the process from `processes`(globle)
// and write the result into `day`(globle)

//#define _DEBUG_ // to debug uncomment this line and run `gcc runpls.c`
#ifdef _DEBUG_
Process processes[10000];
int processesCount;
DayArrange day[3][10000];
int dayCount[3];
time_t startPeiod;
int endPeiod;

int main(){
  // set process...
  // call algrothm
  // print some debug output
  initTime("2022-01-01"); //
  endPeiod = timeToInt("2022-01-30");
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
  //   day[].Product.orderNumber,
  //   day[m].Product.dueDate,
  //   day[m].Product.quantity,
  //   day[m].Product.categorie,
  //   day[m].Product.accepted);
  // }
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
}
#endif


void FCFS(){
  int i,j,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod;
  int YDays=endPeiod;
  int ZDays=endPeiod;
  int currentDay=0;

  int XYZStatus[3]={0,0,0};
  for(i=0;i<processesCount;i++){
    int productivity=0;
    loop:
    for(k=0;k<3;k++){
      while(XYZStatus[0]!=0&&XYZStatus[1]!=0&&XYZStatus[2]!=0){
        XYZStatus[0]--;
        XYZStatus[1]--;
        XYZStatus[2]--;
        currentDay++;
      }
      if (XYZStatus[k]==0){
        if(k==0){

          productivity=300;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){
            processes[i].accepted=0;
            continue;
          }
          else if(needDays<=processes[i].dueDate-currentDay&&needDays<=XDays){
            XYZStatus[k]=needDays;
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
            processes[i].accepted=0;
          }

        }else if(k==1){

          productivity=400;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){
            processes[i].accepted=0;
            continue;
          }
          if(needDays<=processes[i].dueDate-currentDay&&needDays<=YDays){
            XYZStatus[k]=needDays;
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
            processes[i].accepted=0;
          }

        }else if(k==2){

          productivity=500;
          int needDays=processes[i].quantity/productivity;
          int jugde=processes[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>processes[i].dueDate-currentDay){
            processes[i].accepted=0;
            continue;
          }
          else if(needDays<=processes[i].dueDate-currentDay&&needDays<=ZDays){
            XYZStatus[k]=needDays;
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
            processes[i].accepted=0;
          }

        }
      }

    }

  }
}



void priorityScheduling() {
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

  // the above is good, the rest is wrong,
  // don't need to change, there's a simple way
  // do the FCFS toghter and copy it
  // it is the same for the rest
  int j,k;
  int avaliableDays=endPeiod;
  int XDays=endPeiod;
  int YDays=endPeiod;
  int ZDays=endPeiod;
  int currentDay=0;

  int XYZStatus[3]={0,0,0};
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
        if(k==0){
          productivity=300;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=XDays){
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }else if(k==1){

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
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }else if(k==2){

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
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }
      }
    }
  }
}


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
  int XDays=endPeiod;
  int YDays=endPeiod;
  int ZDays=endPeiod;
  int currentDay=0;

  int XYZStatus[3]={0,0,0};
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
        if(k==0){

          productivity=300;
          int needDays=rawDay[i].quantity/productivity;
          int jugde=rawDay[i].quantity%productivity;
          if(jugde!=0){
            needDays++;
          }
          if(needDays>rawDay[i].dueDate-currentDay){
            processes[acceptedIndex[i]].accepted=0;
          }
          else if(rawDay[i].dueDate-currentDay>=needDays&&needDays<=XDays){
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }else if(k==1){

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
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }else if(k==2){

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
            XYZStatus[k]=needDays;
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
            processes[acceptedIndex[i]].accepted=0;
          }

        }
      }
    }
  }
}

void runPLS(int alg) {
  switch (alg) {


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
