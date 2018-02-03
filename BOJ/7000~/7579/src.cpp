//https://www.acmicpc.net/problem/7579
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int app[2][101];//app[0][i] :: 메모리 mi, app[1][i] :: 비용 ci
int dp[10001]; //dp[i] :: 비용 i가 가능할 때 최대의 메모리

int main()
{
     int n, m, tmp;
     cin >> n >> m;
     tmp=0;

     for(int i=0; i<2; i++)
     {
          for(int j=0; j<n ;j++)
               {
                    cin >> app[i][j];
                    if(i==1 && app[i][j]==0) tmp+=app[i][j];
               }
     }
     if(tmp>=m) {cout << "0"; return 0;}

     memset(dp,-1,sizeof(dp));
     for(int i=0; i<=m; i++)
     {
          dp[0]=max(app[0][i])
     }
}
