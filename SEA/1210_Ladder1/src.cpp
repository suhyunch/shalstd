#include <iostream>
using namespace std;
int map[100][100];
bool visit[100][100];

int dy[3]={0, 0, 1};
int dx[3]={-1, 1, 0};

bool dfs(int y, int x)
{
  for(int i=0; i<3; i++)
  {
    visit[y][x]=1;
    int ny=y+dy[i];
    int nx=x+dx[i];

    if(ny==99)
      { if(map[99][nx]==2) return 1; else return 0;}

    if(nx>=0 && nx<100 && ny>=0 && ny<100 & map[ny][nx] && !visit[ny][nx])
    {
      return dfs(ny,nx);
    }
    visit[y][x]=0;
  }
}

int main()
{
  for(int T=1; T<=10; T++)
  {
    int bin;
    cin >> bin;
    cout << "#" << T <<" ";

    for(int i=0; i<100; i++)
      for(int j=0; j<100; j++)
        cin >> map[i][j];

    for(int i=0; i<100; i++)
    {
      for(int j=0; j<100; j++)
      	for(int k=0; k<100; k++)
        {   visit[j][k]=0; }


      if(map[0][i] && dfs(0,i)) { cout << i << endl; break;}
    }
  }
}
