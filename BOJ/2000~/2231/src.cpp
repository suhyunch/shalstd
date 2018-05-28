//https://www.acmicpc.net/problem/2231
#include <iostream>
using namespace std;

int main(){
     int n;
     cin >> n;

     int ans=0;
     for(int i=1; i<=n; i++){
          int tmp=i;
          int sum=i;
          while(tmp>0){
               sum+=tmp%10;
               tmp/=10;
          }
          if(sum==n) {
               ans=i;
               break;
          }
     }
     cout << ans;
     return 0;
}
