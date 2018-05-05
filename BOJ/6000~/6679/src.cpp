//https://www.acmicpc.net/problem/6679
#include <iostream>
using namespace std;

int main(){
     for(int i=1000; i<=9999; i++){
          int a=0, b=0;

          int tmp=i;
          while(tmp>0){
               a+=tmp%10;
               tmp/=10;
          }
          tmp=i;
          while(tmp>0){
               b+=tmp%12;
               tmp/=12;
          }
          if(a!=b) continue;
          tmp=i;
          b=0;
          while(tmp>0){
               b+=tmp%16;
               tmp/=16;
          }
          if(a!=b) continue;
          cout << i<<endl;
     }
     return 0;
}
