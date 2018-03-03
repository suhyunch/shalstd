//https://www.acmicpc.net/problem/2622
#include <iostream>
using namespace std;

int main(){
     int n;
     int cnt=0;

     cin >> n;

     for(int a=1; a<=n; a++){
          for(int b=a; b<=n; b++){
               int c=n-(a+b);
               if(c<b) break;
               if(c<a+b) cnt++;
          }
     }
     cout << cnt;

     return 0;
}
