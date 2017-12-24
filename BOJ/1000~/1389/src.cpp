#include <iostream>
#include <queue>
using namespace std;
bool map[102][102];
bool visit[101] = {0};
int N, M;
int sum;

int bfs(int start, int end)
{
  queue< pair< int, int> > q;
  for(int i=1; i<=N; i++) visit[i] = 0;
  q.push({start, 0});

  while(!q.empty())
  {
    int x=q.front().first;
    int num=q.front().second;
    q.pop();

    if(x==end) {return num;}
    for(int i=1; i<=N; i++)
      if(i!= start && map[x][i] && !visit[i]) { q.push({i, num+1});     visit[i]=1;}
    }
}
int main()
{
    cin >> N >> M;

    for(int i=1; i<=M; i++)
    {
        int a, b;
        cin >> a >> b;

        map[a][b]=1;
        map[b][a]=1;
    }

    int min = 100;
    int min_index;
    for(int i=1; i<=N; i++)
    {
        sum=0;
        for(int j=1; j<=N; j++)
        {
              visit[i]=1;
              if(i!=j) sum+=bfs(i,j);
         }
        if(min>sum) { min=sum; min_index=i;}
    }

    cout << min_index;
}
