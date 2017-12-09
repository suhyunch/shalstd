//https://www.acmicpc.net/problem/11054
#include <iostream>
using namespace std;

int main()
{
     int A[1001];
     int dp[2][1001];
     int N,x,max;

     cin >> N;

     for(int i=1; i<=N; i++) cin >> A[i];

     dp[0][1]=0;
     dp[1][N]=0;
//A[i]에서 이전까지의 원소들에 대한 증가 수열의 길이, 본인은 제외하고 카운트
     for(int i=2; i<=N; i++)
     {
          max=0;
          for(int j=i-1; j>0; j--)
          {
               x=0;
               if(A[i]>A[j]) x=dp[0][j]+1;
               if(max<x) max=x;
          }
          dp[0][i]=max;
     }

     //A[i]에서 이후의 원소들에 대한 감소 수열의 길이, 본인은 제외하고 카운트
          for(int i=N-1; i>=1; i--)
          {
               max=0;
               for(int j=i+1; j<=N; j++)
               {
                    x=0;
                    if(A[i]>A[j]) x=dp[1][j]+1;
                    if(max<x) max=x;
               }
               dp[1][i]=max;
          }
     max=0;
     for(int i=1; i<=N; i++)
          if(max<(dp[0][i]+dp[1][i])) max=dp[0][i]+dp[1][i];

     cout << max+1;
}
