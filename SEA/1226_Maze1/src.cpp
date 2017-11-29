#include <iostream>
using namespace std;
int map[16][16];
bool visit[16][16];
bool chk;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int y, int x)
{
  for(int i=0; i<4; i++)
  {
    visit[y][x]=1;
    int ny=y+dy[i];
    int nx=x+dx[i];

    if(map[ny][nx]==3) chk=1;

    if(!visit[ny][nx] && !map[ny][nx])
      dfs(ny,nx);
    visit[y][x]=0;
  }
}

 int main()
 {
   for(int T=1; T<=10; T++)
   {
     chk=0;
     int tc;
     cin >> tc;
     for(int i=0; i<16; i++)
     {
       char input[16];
       cin >> input;
       for(int j=0; j<16; j++)
        map[i][j]=input[j]-'0';
      }
      cout << "#" << T << " ";
      dfs(1,1);

      if(chk) cout << "1\n";
      else cout << "0\n";
   }
 }
