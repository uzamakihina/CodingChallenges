

// PANCAKE FLIPPER     - given a string line of "-" and "+" and a flipper size (n), we can only flip n consecutive pancakes at a time.
// When a "+" is flipped it becomes a "-" and vice versa.
// Try to flip the pancakes in the least amount of flips so so all the characters are "+" and display the amount of flips.
// If this cannot be done then say its impossible.








#include <stdio.h>
#include <stdlib.h>

void flipPancakes(FILE *fp, int test);
FILE *rp;


int main(){


rp = fopen("PancakeOutput.txt", "w");
FILE *fp;
fp = fopen("Pancakes.txt", "r");
int cases;
fscanf(fp,"%d",&cases );
char temp[100];
fgets(temp,100,fp);

printf("Cases = %d\n", cases);

for(int i = 0 ; i < cases ; i++){
  flipPancakes(fp, i);
  fgets(temp,100,fp);

}


}

void flipPancakes(FILE *fp, int test){

  char line[100] = {0};
  int flippersize;
  fscanf(fp, "%s", line);
  fscanf(fp, "%d", &flippersize);

  int flips = 0;
  int index = 0;
  while(line[index+flippersize-1] != 0){

    if (line[index] == '-'){
      flips++;
      for(int i = index ;i < flippersize+index ; i++){
        if(line[i] == '-') line[i] = '+';
        else line[i] = '-';
      }
    }

    index++;
  }

  int possible = 1;
  index = 0;
  while(line[index] != 0){
    if(line[index] == '-') {
      possible = 0;
      break;
    }
    index++;
  }



  if (possible) fprintf(rp,"Case #%d: %d\n", test+1,flips);
  else fprintf(rp,"Case #%d: IMPOSSIBLE\n", test+1);





}
