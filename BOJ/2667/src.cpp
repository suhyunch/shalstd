#include <iostream>
#include <algorithm>
using namespace std;;
bool map[28][28];
bool visit[28][28];
int num[320];
int cnt_d;
int cnt;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(int x, int y)
{
  for(int i=0; i<4; i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];

    if(map[nx][ny] && !visit[nx][ny])
    {
      visit[nx][ny]=1;
      cnt_d++;
      dfs(nx,ny);
    }
  }
}
int main()
{
  int N;
  cin >> N;
  char in[25];
  for(int i=1; i<=N; i++)
  {
    cin >> in;
    for(int j=1; j<=N; j++)
    map[i][j]=in[j-1]-'0';
  }

  for(int i=1; i<=N; i++)
    for(int j=1; j<=N; j++)
      if(!visit[i][j]&& map[i][j])
      {  visit[i][j]=1; cnt_d=1;  dfs(i,j); num[cnt]=cnt_d; cnt++;  }

  sort(num,num+cnt); // 0부터 cnt개의 단지 개수만큼 sort
  cout << cnt << endl;
  for(int i=0; i<cnt; i++) cout << num[i] << endl;
}
