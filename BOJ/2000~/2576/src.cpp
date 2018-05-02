//https://www.acmicpc.net/problem/2576
#include <iostream>
using namespace std;

int main(){
     int num[7];
     int sum=0;
     int mn=101;
     for(int i=0; i<7; i++){
          cin>> num[i];
          if(num[i]%2) {
               sum+=num[i];
               if(num[i]<mn) mn=num[i];
          }
     }
     if(sum==0) cout <<"-1";
     else cout << sum <<endl<<mn <<endl;

     return 0;

}
