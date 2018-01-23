//https://www.acmicpc.net/problem/1937
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int map[502][502];
int dp[502][502];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
  int n;
int mov(int nowy, int nowx)
{
     if(dp[nowy][nowx]==0)
     {
          dp[nowy][nowx]=1;
          int nexty, nextx;
          for(int i=0; i<4; i++)
          {
               nexty=nowy+dy[i];
               nextx=nowx+dx[i];

               if(map[nexty][nextx]>map[nowy][nowx])
               {
                         dp[nowy][nowx]=max(dp[nowy][nowx],mov(nexty,nextx)+1);
               }
          }
     }
     return dp[nowy][nowx];
}

int main()
{
  scanf("%d", &n);

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
     scanf("%d",&map[i][j]);

     int ans=0;

     for(int i=1; i<=n; i++)
       for(int j=1; j<=n; j++)
                ans=max(ans,mov(i,j));

       printf("%d",ans);
}
