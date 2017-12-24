//https://www.acmicpc.net/problem/1890
#include <iostream>
using namespace std;
long long map[100][100];
long long dp[100][100];
int main()
{
     int n;
     cin >> n;

     for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
               cin >> map[i][j];

     dp[0][0]=1;
     int l=0;
     int c=0;
     for(int i=0; i<n; i++)
     {
          for(int j=0; j<n; j++)
          {
               while(l<n && c<n)
               {
                    l=
               }
          }
     }
     cout << dp[n-1][n-1];
}
