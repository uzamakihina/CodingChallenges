



// Problem description link
//https://code.google.com/codejam/contest/8294486/dashboard


#include <iostream>

using namespace std;

void find_speed(FILE *fp, int trail);
FILE *rp;
int main(){


  FILE *fp;

  fp = fopen("SpeedStatsCases.txt", "r");
  rp = fopen("CruiseSpeeds.txt", "w");

  int cases;
  fscanf(fp, "%d", &cases);



  for(int i = 0 ; i < cases; i++){
    find_speed(fp,i);

  }


}

void find_speed(FILE *fp, int trail){

  float distance, horses;
  fscanf(fp,"%f %f", &distance, &horses);

  float slowestTime;
  float starting, speed, time;
  fscanf(fp,"%f %f", &starting, &speed);
  slowestTime = (distance - starting)/speed;


  for(int i = 1 ; i < horses ; i++){

    fscanf(fp,"%f %f", &starting, &speed);
    time = (distance - starting)/speed;
    if(time > slowestTime) slowestTime = time;

  }

  fprintf(rp, "Case %d: fastest cruise speed is %f \n",trail+1, distance/slowestTime);



}
