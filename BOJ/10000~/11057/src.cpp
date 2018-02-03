//https://www.acmicpc.net/problem/11057
#include <iostream>
using namespace std;
int dp[10][1001];

int main()
{
     int n, sum;
     cin >> n;
     if(n==1) { cout <<"10"; return 0;}
     for(int i=0; i<10; i++) dp[i][1]=1;

     sum=1;
     for(int i=2; i<=n; i++)
     {
          dp[0][i]=1;
          for(int j=1; j<10; j++)
          {
               dp[j][i]=(dp[j-1][i]+dp[j][i-1])%10007;
               if(i==n) sum=(sum+dp[j][i])%10007;
          }
     }
     cout << sum%10007;
}
