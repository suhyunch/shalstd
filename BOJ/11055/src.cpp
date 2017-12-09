//https://www.acmicpc.net/problem/11055
#include <iostream>
using namespace std;

int main()
{
     int n;
     cin >> n;

     int A[1001];
     int dp[1001];
     int x,max;
     for(int i=1; i<=n; i++) cin >> A[i];
     dp[1]=A[1];
     for(int i=2; i<=n; i++)
     {
          max=0;
          for(int j=i-1; j>0; j--)
          {
               x=A[i];
               if(A[i]>A[j]) x=dp[j]+A[i];
               if(max<x) { max=x; }
          }
          dp[i]=max;

     }

     max=0;
     for(int i=1; i<=n; i++)
          if(max<dp[i]) max=dp[i];

     cout << max;
}
