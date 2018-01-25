//https://www.acmicpc.net/problem/2616
#include <iostream>
#include <algorithm>
using namespace std;
int dp[4][50001];
int train[50001];

int main()
{
     int n,m;
     cin >> n;
     for(int i=1; i<=n; i++)
     {
          int x;
          cin >> x;
          train[i]=train[i-1]+x;
     }
     cin >> m;

     for(int i=1*m; i<=n; i++)
          dp[1][i]=max(train[i]-train[i-m],dp[1][i-1]);
     for(int i=2*m; i<=n; i++)
          dp[2][i]=max(train[i]-train[i-m]+dp[1][i-m],dp[2][i-1]);
     for(int i=3*m; i<=n; i++)
          dp[3][i]=max(train[i]-train[i-m]+dp[2][i-m],dp[3][i-1]);


     cout << dp[3][n];
}
