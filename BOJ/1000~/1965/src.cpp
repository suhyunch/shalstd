//https://www.acmicpc.net/problem/1965
#include <iostream>
using namespace std;

int main()
{
     int n;
     cin >> n;

     int box[1001];
     int dp[1001];
     int x,max;
     for(int i=1; i<=n; i++) cin >> box[i];
     dp[1]=1;
     for(int i=2; i<=n; i++)
     {
          max=0;
          for(int j=i-1; j>0; j--)
          {
               x=1;
               if(box[i]>box[j]) x=dp[j]+1;
               if(max<x) max=x;
          }
          dp[i]=max;
     }

     max=0;
     for(int i=1; i<=n; i++)
          if(max<dp[i]) max=dp[i];

     cout << max;
}
