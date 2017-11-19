#include <iostream>
using namespace std;
int N, M;
bool map[1002][1002];
bool visit[1001];

void dfs(int y)
{
  visit[y]=1;
  for(int i=1; i<=N; i++)
    if(map[y][i] && !visit[i])
      dfs(i);
}

int main()
{
  int cnt=0;
  cin >> N >> M;

  for(int i=0; i<M; i++)
  {
    int u, v;
    cin >> u >> v;
    map[u][v]=1;
    map[v][u]=1;
  }

  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<=N; j++)
     {
       if(map[i][j] && !visit[j])
        {
          dfs(i);
          cnt++;
        }
     }
  }
  for(int i=1; i<=N; i++)
  if(!visit[i]) cnt++;
  cout << cnt;
}
