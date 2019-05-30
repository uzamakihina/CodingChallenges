

#include <iostream>
#include <string>

using namespace std;

int main(){


  string str;
  getline(cin,str);

  int length = str.length();


  int max = 0, current = 0;

  for(int i = 0 ; i < length ; i++){


    if( isalpha(str[i]) ){
      while(isalpha(str[i])){
        i++;
      }

      current++;

    }

    if (str[i] == '.' || str[i] == '?' || str[i] == '!' || i == length){

      if (current > max) max = current;
      current = 0;
    }



  }

  cout << max;






}
