//https://www.acmicpc.net/problem/1065
#include <iostream>
using namespace std;

int main()
{
     int n,cnt;
     cin >> n;

     cnt=n;
     for(int i=1; i<=n; i++)
     {
          int now=i;
          int diff=now%10-(now%100)/10;
          while(now/10>0)
          {
               if(now%10-(now%100)/10 != diff) {cnt--; break;}
               now/=10;
          }
      }
     cout << cnt;
}
