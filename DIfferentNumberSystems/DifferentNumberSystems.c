// DIFFERENT NUMBER SYSTEMS     - We take a number from a number system, with the following input, and output the same value
// in the third provided system.
// For example:
// "18" "0123456789" "01" the output should be 100100
// Or
// "!##" "#!@" "0123456789" the output should be 8



# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>


void getValues(char number[], char system[], char new[], char words[]);
void print_answer(char words[], int testnum);
FILE *rp;

int main(){

  rp = fopen("LanguageOutput.txt", "w");
  FILE *fp;
  fp = fopen("LanguageInput.txt", "r");
  char words[100] = {0};
  fgets(words,100,fp);
  int cases = atoi(words);


  for( int i = 0 ; i < cases ; i++){
  memset(words,0,100);
  fgets(words,100,fp);
  print_answer(words,i);
  }
}

void print_answer(char words[], int testnum){

  char number[100]= {0};
  char system[100]= {0};
  char new[100] = {0};


  getValues(number, system, new, words);

  int value = 0, value_size = 0, system_size = 0, new_size = 0;

  while(number[value_size] != 0){
    value_size++;
  }

  while(system[system_size] != 0){
    system_size++;
  }

  while(new[new_size] != 0){
    new_size++;
  }

  for( int i = value_size - 1 ; i >= 0 ; i-- ){
    int location = 0;
    char current = number[(value_size - 1) - i];
    while(system[location]!= current){
      location++;
    }
    value = value + (location * pow(system_size, i));

  }

  char newValue[100] = {0};
  int remainder = 0, current = 0, index = 0;

  while(value != 0){
  current = value;
  value = value/new_size;
  remainder = current%new_size;
  newValue[index] = new[remainder];
  index++;
  remainder = 0;
  }

  char reversedString[100] = {0};
  for(int i = 0 ; i< index; i++){
    reversedString[i] = newValue[index-1-i];
  }

  fprintf(rp,"Case %d: %s\n", testnum+1, reversedString);

}

void getValues(char number[], char system[], char new[], char words[]){

  int index = 0, smallIndex = 0;

  while(words[index] != ' '){

    number[smallIndex] = words[index];
    index++;
    smallIndex++;

  }
  index++;

  smallIndex = 0;
  while(words[index] != ' '){

    system[smallIndex] = words[index];
    index++;
    smallIndex++;

  }
  index++;

  smallIndex = 0;
  while(words[index] != '\n'){
    new[smallIndex] = words[index];
    index++;
    smallIndex++;

  }
}
