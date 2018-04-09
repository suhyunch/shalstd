#include <iostream>
using namespace std;

int map[20][20];
bool visited[101];

int dy[4]={1,1,-1,-1};
int dx[4]={1,-1,-1,1};
int N, mx;
int progress[4];

void input(){
     cin >>N;

     for(int i=0; i<N; i++)
          for(int j=0; j<N; j++)
               cin >> map[i][j];

     return;
}
void dfs(int sy, int sx, int y, int x, int dir, int depth);
int main(){
     int tc;
     cin >>tc;

     for(int T=1; T<=tc; T++){
          input();

          mx=0;
          for(int i=0; i<N-2; i++){
               for(int j=1; j<N-1; j++){
                    visited[map[i][j]]=1;
                    dfs(i, j, i, j, 0, 1);
                    visited[map[i][j]]=0;
               }
          }

          if(mx==0) mx=-1;
          cout << "#" <<T<< " " <<mx<<endl;
     }
     return 0;
}



void dfs(int sy, int sx, int y, int x, int dir, int depth){
     for(int i=dir; i<=dir+1; i++){
          if(i!=0 && progress[i-1]==0) continue;
          int ny=y+dy[i];
          int nx=x+dx[i];
          if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[map[ny][nx]] && i<4){
               visited[map[ny][nx]]=1;
               progress[i]++;
               dfs(sy, sx, ny, nx, i, depth+1);
               progress[i]--;
               visited[map[ny][nx]]=0;
          }
          if(i==3 && sy==ny && sx==nx){
               if(mx<depth) mx=depth;
               return;
          }
     }

     return;
}
