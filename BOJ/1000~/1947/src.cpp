//https://www.acmicpc.net/problem/1947
#include <iostream>
using namespace std;
int dp[2][1000001];
int main()
{
     int n;
     dp[0][1]=0;
     dp[1][1]=0;
     cin << n;

     for(int i=2; i<=n; i++)
     {
          dp[0][i]=dp[0][i-1]*(n-i);
          dp[1][i]=dp[1][i-1]*(n-i+1);
     }

     cout << dp[0][n]+dp[1][n];
}
