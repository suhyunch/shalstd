//https://algospot.com/judge/problem/read/TRIANGLEPATH
#include <iostream>
using namespace std;
int dp[101][101];
int tri[101][101];

int main()
{
     int c;
     cin >> c;
     for(int t=0; t<c; t++)
     {
          int n;
          cin >> n;

          for(int i=1; i<=n; i++)
               for(int j=1; j<=i; j++)
                    cin >> tri[i][j];

          dp[1][1]=tri[1][1];

          for(int i=1; i<=n; i++)
          {
               dp[i][1]=tri[i][1]+dp[i-1][1];
               for(int j=2; j <i ; j++)
               {
                    if(dp[i-1][j]>dp[i-1][j-1])
                         dp[i][j]=tri[i][j]+dp[i-1][j];
                    else
                         dp[i][j]=tri[i][j]+dp[i-1][j-1];
               }
               dp[i][i]=tri[i][i]+dp[i-1][i-1];
          }

          int max1=0;
          for(int i=1; i<=n; i++)
               if(max1<dp[n][i]) max1=dp[n][i];

          cout << max1 << endl;
     }
}
