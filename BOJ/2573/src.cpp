#include <cstdio>
using namespace std;
int map_melting[302][302];
int map_origin[302][302];
bool visit[302][302];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int y, int x)
{
  visit[y][x]=1;
  for(int i=0; i<4; i++)
  {
    int ny=y+dy[i];
    int nx=x+dx[i];
    if(map_origin[ny][nx] != 0 && !visit[ny][nx])
      dfs(ny, nx);
  }
}

int main()
{
  int N, M;
  scanf("%d %d",&N,&M);

  /*input*/
  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
    {scanf("%d",&map_origin[i][j]);}

  int land=0;
  int year=0;
  while(1)
  {
    for(int i=2; i<N; i++)
     for(int j=2; j<M; j++)
      visit[i][j]=0;
      land=0;
      bool chk=0;
      for(int i=2; i<N; i++)
       for(int j=2; j<M; j++)
      {
        if(map_origin[i][j] != 0 && !visit[i][j])
        {
          if(land==1)
          {printf("%d",year); return 0;}
        dfs(i,j); land++;
      }
        if(map_origin[i][j]>0 && !chk) chk=1;
      }
      if(!chk) {printf("0"); return 0;}
    /*melting_iceburg*/
    for(int i=1; i<N; i++)
    {
      for(int j=1; j<M; j++)
      {
        if(!map_origin[i][j]) continue;
        int cnt=0;
        if(!map_origin[i][j-1]) cnt++;
        if(!map_origin[i][j+1]) cnt++;
        if(!map_origin[i-1][j]) cnt++;
        if(!map_origin[i+1][j])cnt++;
        map_melting[i][j]= map_origin[i][j]-cnt;
        if(map_melting[i][j]<0) map_melting[i][j]=0;
      }
    }  /*melting_iceburg*/
    for(int i=1; i<=N; i++)
      for(int j=1; j<=M; j++)
      {  map_origin[i][j]=map_melting[i][j];}

      year++;
  }

}
