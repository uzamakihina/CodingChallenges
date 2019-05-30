
// Given the max index x,y on a 2d grid from the user. Print all possible paths that a robot can go
// to reach the bottom right starting from the top left Assuming the robot can only go one down or one right
// Every step.

#include <iostream>
using namespace std;

class block{
public:
  int x;
  int y;

  block(){}

  block(int h,int v){
    x = h;
    y = v;
  }
};


void robotWalk(int x, int y, block path[], int size);
int x_max,y_max;

int main(){

  cout << "Enter the max index of horizontal blocks: ";
  cin >> x_max;
  cout << "Enter the max index of verticle blocks: ";
  cin >> y_max;

  block path[x_max*y_max];
  int size = 0;


  robotWalk(0,0,path,size);


}



void robotWalk(int x, int y, block path[], int size){

  path[size].x = x;
  path[size].y = y;


  if (x == x_max && y == y_max){

    for(int i = 0 ; i < size ; i++){

      printf("(%d,%d) ", path[i].x, path[i].y);

    }
    printf("(%d, %d)\n", x_max, y_max);

    return;

  }

  if(x < x_max){
    robotWalk(x+1,y,path,size+1);
  }

  if(y < y_max){
    robotWalk(x,y+1,path,size+1);
  }






}
