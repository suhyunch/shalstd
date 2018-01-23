//https://www.acmicpc.net/problem/1937
#include <iostream>
#include <stdio.h>
using namespace std;
long map[502][502];
int dp[502][502];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
  int n;
int max1;
int mov(int nowy, int nowx)
{
     int nexty, nextx;
     for(int i=0; i<4; i++)
     {
          nexty=nowy+dy[i];
          nextx=nowx+dx[i];

          if((map[nexty][nextx]>map[nowy][nowx]) && (dp[nexty][nextx]<dp[nowy][nowx]+1))
          {
                    dp[nexty][nextx]=dp[nowy][nowx]+1;
                    if(dp[nexty][nextx]>max1) max1=dp[nexty][nextx];
                    mov(nexty, nextx);
          }
     }
}

int main()
{
  scanf("%d", &n);

 for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
     scanf("%d", &map[i][j]);


     for(int i=1; i<=n; i++)
       for(int j=1; j<=n; j++)
       {
            if(dp[i][j]==0) // 탐색한 적이 없으면
            {
                 dp[i][j]=1;
                 if(max1 !=n*n) mov(i,j);
            }
       }

       printf("%d",max1);
}
