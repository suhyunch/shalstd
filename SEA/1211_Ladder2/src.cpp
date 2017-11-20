#include <iostream>
using namespace std;
int map[100][100];
bool visit[100][100];

int dy[3]={0, 0, 1};
int dx[3]={-1, 1, 0};

int dfs(int y, int x, int depth)
{
  for(int i=0; i<3; i++)
  {
    visit[y][x]=1;
    int ny=y+dy[i];
    int nx=x+dx[i];

    if(ny==99) {return depth;}
    if(nx>=0 && nx<100 && ny>=0 && ny<100 & map[ny][nx] && !visit[ny][nx])
    {  return dfs(ny,nx, depth+1);}
    visit[y][x]=0;
  }
}

int main()
{
  for(int T=1; T<=10; T++)
  {
    int bin;
    int min_i;
    cin >> bin;
    cout << "#" << T <<" ";

    for(int i=0; i<100; i++)
      for(int j=0; j<100; j++)
        cin >> map[i][j];
    int min=10000;
    for(int i=99; i>=0; i--)
    {
      /*initialize*/
      for(int j=0; j<100; j++)
      	for(int k=0; k<100; k++)
        {   visit[j][k]=0; }



      if(map[0][i])
      {
        int cnt= dfs(0, i, 0);
        if(min>cnt)  { min=cnt;  min_i=i;}
      }
    }
    cout << min_i << endl;
  }
}
