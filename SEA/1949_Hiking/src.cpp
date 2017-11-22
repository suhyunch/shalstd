#include <iostream>
using namespace std;
int map[10][10];
bool visit[10][10];
int N , k, max_h, l_way;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void dfs(int cnt, int y, int x, bool op)
//cnt : 등산로 길이, y,x : 좌표, op : 공사를 했는지 안했는지 - 0 안함, 1 함
{
  visit[y][x]=1;

  for(int i=0; i<4; i++)
  {

    int ny = y + dy[i];
    int nx = x + dx[i];
    if(ny < 1 || ny > N || nx < 1 || nx > N) continue;
    if(visit[ny][nx]) continue;

    if(map[ny][nx] < map[y][x])
    {
      dfs(cnt+1, ny,nx, op);
      visit[ny][nx]=0;
    }
    else if(map[ny][nx] >= map[y][x] && !op)
    {
        for(int j=1; j<=k; j++)
        {
          op=1;
          map[ny][nx] -= j;
          if(map[ny][nx] < map[y][x])
          {
            dfs(cnt+1, ny, nx, op);
            visit[ny][nx]=0;
          }
          map[ny][nx] += j;
          op=0;
        }
    }
    if(l_way<cnt) l_way=cnt;
  }
}


int main()
{
  int tc;
  cin >> tc;
  for(int T=1; T<=tc; T++)
  {
    cin >> N >> k;
    max_h=0;
    l_way=0;

    /*initialize_map*/
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) map[i][j]=0;
    /*input*/
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        {
          cin >> map[i][j];
          if(max_h<map[i][j])
            max_h=map[i][j];
        }


    for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++)
      {
        if(map[i][j]==max_h)
        {
          /*initialize_visit*/
          for(int i=0; i<10; i++) for(int j=0; j<10; j++) visit[i][j]=0;
          dfs(1,i,j,0);
        }
      }
      cout << "#" << T << " " << l_way << endl;
  }
}
