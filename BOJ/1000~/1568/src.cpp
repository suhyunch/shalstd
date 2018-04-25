//https://www.acmicpc.net/problem/1568
#include <iostream>
using namespace std;

int main(){
     int n;
     cin >>n;

     int ans=0;
     while(1){
          for(int i=1; n>=i ; i++){
               n-=i;
               ++ans;
          }
          if(n==0) break;
     }
     cout << ans <<endl;
     return 0;
}
