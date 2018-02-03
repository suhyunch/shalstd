//https://www.acmicpc.net/problem/11722
#include <iostream>
using namespace std;

int main()
{
     int A[1001];
     int dp[1001];
     int N,x,max;

     cin >> N;

     for(int i=1; i<=N; i++) cin >> A[i];

     dp[1]=1;

     for(int i=2; i<=N; i++)
     {
          max=0;
          for(int j=i-1; j>0; j--)
          {
               x=1; //자기 자신의 길이가 최초인 경우 항상 1
               if(A[i]<A[j]) x=dp[j]+1;
               if(max<x) max=x;
          }
          dp[i]=max;
     }

     max=0;
     for(int i=1; i<=N; i++)
          if(max<dp[i]) max=dp[i];

     cout << max;
}
