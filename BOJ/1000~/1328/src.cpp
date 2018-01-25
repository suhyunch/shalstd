//https://www.acmicpc.net/problem/1328
#include <iostream>
#define MOD 1000000007
using namespace std;
long long dp[101][101][101];

int main()
{
     int n, l, r;
     long long temp;

     cin >> n >> l >> r;

     dp[1][1][1]=1;
     dp[2][1][2]=dp[2][2][1]=1;

     for(int i=3; i<=n; i++)
     {
          dp[i][i][1]=dp[i][1][i]=1;
          //i=3 일때, 1,2,3  3,2,1 순으로 빌딩 있는 것
          for(int j=1; j<i; j++)
          {
               for(int k=1; k<i; k++)
               {
                    temp=dp[i-1][j][k];
                    temp=(temp*(i-2)) % MOD;
                    temp=(temp+dp[i-1][j-1][k]) % MOD;
                    temp=(temp+dp[i-1][j][k-1]) % MOD;

                    dp[i][j][k]=temp;
               }
          }
     }

     cout << dp[n][l][r];
}
