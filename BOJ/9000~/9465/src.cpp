//https://www.acmicpc.net/problem/9465
#include <iostream>
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

          for(int i=0; i<2; i++)
          {
               for(int j=1; j<=n; j++)
               {

               }
          }
     }
}
