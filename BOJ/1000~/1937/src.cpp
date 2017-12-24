//https://www.acmicpc.net/problem/1937
#include <iostream>
using namespace std;

int map[501][501];
int longest[501][501];
bool visit[501][501];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int max_l;

void dfs(int y, int x, int depth)
{
  visit[y][x]=1;
  if(max_l<depth) max_l=depth;
  for(int i=0; i<4; i++)
  {
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(map[y][x]<map[ny][nx] && longest[ny][nx] !=0) {max_l=depth+longest[ny][nx];}
    if(map[ny][nx]!=0 && !visit[ny][nx]  && map[y][x]<map[ny][nx])
      dfs(ny,nx,depth+1);
  }
  visit[y][x]=0;
}

int main()
{
  int n;
  cin >> n;

  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
     cin >> map[i][j];

  for(int i=1; i<=n; i++)
   for(int j=1; j<=n; j++)
   {
     max_l=0;
     dfs(i,j,1);
     longest[i][j]=max_l;
  }

 max_l=0;
  for(int i=1; i<=n; i++)
   for(int j=1; j<=n; j++)
   if(longest[i][j]>max_l) max_l=longest[i][j];

   cout << max_l;
}
