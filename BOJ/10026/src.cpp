//https://www.acmicpc.net/problem/10026
#include <iostream>
#include <cstring>
using namespace std;
char picture[100][100];
bool visit[100][100];
bool visitbi[100][100];
int n, cnt;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};

void dfs(int y, int x, char c)
{
     visit[y][x]=1;
     for(int i=0; i<4; i++)
     {
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(ny>=0 && ny<n && nx>=0 && nx<n && !visit[ny][nx] && c==picture[ny][nx])
          {
               dfs(ny,nx,c);
          }
     }
}

void dfsbi(int y, int x, char c)
{
     visitbi[y][x]=1;
     for(int i=0; i<4; i++)
     {
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(ny>=0 && ny<n && nx>=0 && nx<n && !visitbi[ny][nx])
          {
               if(c=='B' && picture[ny][nx]=='B')
                    dfsbi(ny,nx,c);
               else if(c=='R' || c=='G')
               {
                    if(picture[ny][nx]=='R'|| picture[ny][nx]=='G')
                         dfsbi(ny,nx,c);
               }
          }
     }
}

int main()
{
     cin >> n;

     //input
     for(int i=0; i<n; i++)
          cin >> picture[i];

     for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
          {
               if(!visit[i][j])
               { cnt++; dfs(i,j, picture[i][j]); }
          }
     cout << cnt << " ";

     cnt=0;
     for(int i=0; i<n; i++)
          for(int j=0; j<n; j++)
          {
               if(!visitbi[i][j])
               { cnt++; dfsbi(i,j, picture[i][j]); }
          }
     cout << cnt << " ";
}
