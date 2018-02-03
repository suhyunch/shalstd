#include <iostream>
using namespace std;
int cafe[22][22];
bool visited[100];
int cnt;
int startx, starty;

int dx[4]={-1,1,1,-1};
int dy[4]={1,1,-1,-1};


int dfs(int nowy, int nowx, int dir)
{
     visited[cafe[nowy][nowx]]=1;
     int nexty=nowy+dy[dir];
     int nextx=nowx+dx[dir];
     if(nowy==starty && nowx==startx) return 0;

     if(!cafe[nexty][nextx] || visited[cafe[nexty][nextx]])
     {
          dir++;
          nexty=nowy+dy[dir];
          nextx=nowx+dx[dir];
     }

     if(!visited[cafe[nexty][nextx]]&& cafe[nexty][nextx]>0)
          { cnt++; dfs(nexty, nexty, dir); cnt--;}

     visited[cafe[nowy][nowx]]=0;
}

int main()
{
     int tc;
     cin >> tc;
     for(int t=1; t<=tc; t++)
     {
          int n;
          cin >> n;
          for(int i=1; i<=n; i++)
               for(int j=1; j<=n; j++)
                    cin >> cafe[i][j];

          /*dfs*/
          for(int i=1; i<=n; i++)
          {
               for(int j=1; j<=n; j++)
               {
                    if(i==1 && j==1) continue;
                    if(i==1 && j==n) continue;
                    if(i==n && j==1) continue;
                    if(i==n && j==n) continue;

                    starty=i;
                    startx=j;
                    cnt=1;

                    dfs(i,j,0);

               }
          }
     }
}
