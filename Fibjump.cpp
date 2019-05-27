


# include <vector>
# include <iostream>

using namespace std;

class platform{
public:
  int lowest;
  vector<int>nextjumps;
  vector<int>path;

  platform(int size){
    lowest = size+1;
  }

};

int main(){

    vector<int> platforms;
    vector<platform*> block;

    int size;

    cin >> size;
    // Initialize platform and blocks;
    for( int i = 0 ; i <= size ; i++){
      platforms.push_back(i%2);
    }

    for(int i = size ; i >= 0 ; i--){
      block.push_back(new platform(size));
      block[size-i]->lowest = size -30;
    }

    platforms[size] = 1;
    platforms[0] = 1;
    block[size]->lowest = 0;

    for(int i = size ; i >= 0 ; i--){

        int last = 1;
        for (int fib = 1; i - fib >= 0; ){

          if ( platforms[i-fib] == 1){

            if (block[i-fib]->lowest > block[i]->lowest + 1){
              block[i-fib]->lowest = block[i]->lowest + 1;

              int number = block[i]->path.size();
              block[i-fib]->path.clear();

              for(int e = 0 ;e < number;e++ ){
                block[i-fib]->path.push_back(block[i]->path[e]);
              }
              block[i-fib]->path.push_back(i);

            }

          }

          int temp = fib;
          fib = fib + last;
          last = temp;

        }

    }

    cout << " \nWith a path of size "<< size +1  << "\n";
    cout << "The path of fibonacci jumps are, starting from block 0 \n";

    int last = 0;
    int number = block[0]->path.size();
    for(int i = 0; i < number ; i++){
      cout << "jump " << block[0]->path[number-i-1] -  block[0]->path[number-i] << " blocks to block " << block[0]->path[number-i-1] << "\n" ;

    }







}
