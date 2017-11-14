#include <iostream>
using namespace std;
int  M, N, K;
bool map[51][51];
int visit[51][51];

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

int cnt;

void dfs(int x, int y)
{
  for(int i=0; i<4; i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];

    if(nx>=0 && nx<N && ny>=0 && ny<M )
    {
      if(map[nx][ny] && visit[nx][ny]==0)
      {
        visit[nx][ny]=cnt;
        dfs(nx,ny);
      }
    }
  }
}

int main()
{
  int T;
  cin >> T;
  for(int tc=0; tc<T; tc++)
  {
    cin >> M >> N >> K;
    //initialize
    for(int i=0; i<51; i++) for(int j=0; j<51; j++) { map[i][j]=0; visit[i][j]=0; }
    cnt = 1;
    //input, map
    for(int i=0; i<K; i++) { int x,y; cin >> x >> y; map[y][x]=1;}
    for(int i=0; i<N; i++) for(int j=0; j<M; j++) if(!visit[i][j]&& map[i][j]) { dfs(i,j); cnt++; }
    cout << cnt -1 << endl;
  }
}
