//https://www.acmicpc.net/problem/9465
#include <iostream>
#include <algorithm>
using namespace std;
int score[2][100001];
int dp[2][100001];
int main()
{
     int t;
     cin >> t;

     for(int tc=0; tc<t; tc++)
     {
          int n;
          cin >> n;

          for(int i=1; i<=n; i++) cin >> score[0][i];
          for(int i=1; i<=n; i++) cin >> score[1][i];

          dp[0][1]=score[0][1];
          dp[1][1]=score[1][1];
          dp[0][2]=score[1][1]+score[0][2];
          dp[1][2]=score[0][1]+score[1][2];

          for(int i=2; i<=n; i++)
          {
               for(int j=0; j<2; j++){
                    dp[j][i] = max(dp[1 - j][i - 1], dp[1 - j][i - 2]) + score[j][i];
               }
          }


          cout << max(dp[0][n],dp[1][n])<<endl;

          for(int i=0; i<=n; i++) dp[0][i]=dp[1][i]=0;
     }
}
