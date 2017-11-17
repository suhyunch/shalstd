#include <iostream>
using namespace std;
int map[102][102];
bool visit[102][102];
int N;

int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void dfs(int y, int x, int r_height)
{
  visit[y][x] = 1;

  for(int i=0; i<4; i++)
  {
    int nx=x+dx[i];
    int ny=y+dy[i];

    if((map[ny][nx]-r_height)>0 && !visit[ny][nx])
    {
      dfs(ny, nx, r_height);
    }
  }
}

int main()
{
  int m_height=0;
  int m_area=1;

  cin >> N;

 /*input*/
  for(int i=1; i<=N; i++) for(int j=1; j<=N; j++)
  {
     cin >> map[i][j];
     if(m_height<map[i][j]) m_height=map[i][j];
   }

   for(int i=1; i<=m_height; i++)
   {
     int tmp_area=0;
     /*initialize*/
     for(int j=1; j<=N; j++) for(int k=1; k<=N; k++) visit[j][k]=0;

     for(int j=1; j<=N; j++)
      for(int k=1; k<=N; k++)
      {
        if((map[j][k]-i)>0 && !visit[j][k] )
        {
          dfs(j, k, i);
          tmp_area++;
       }
      }
      if(m_area<tmp_area) m_area=tmp_area;
   }// for(int i=2; i<=m_height; i++)
   cout << m_area;
}//int main()
