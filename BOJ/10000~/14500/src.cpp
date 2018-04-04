//https://www.acmicpc.net/problem/14500
#include <iostream>
#include <algorithm>
using namespace std;

int map[500][500];
bool visited[500][500];

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
int N, M;
int mx=0;

void solve(int y, int x, int now);
void dfs(int y, int x, int now, int depth);
/*
void init(int y, int x){
     for(int i=y-1; i<=y+1; i++){
          for(int j=x-1; j<=x+1; j++)
               visited[i][j]=0;
     }
}*/
int main(){
      cin >> N >> M;

      for(int i=0; i<N; i++){
           for(int j=0; j<M; j++){
                cin >> map[i][j];
           }
      }

      for(int i=0; i<N; i++){
           for(int j=0; j<M; j++){
                solve(i, j, map[i][j]);
                visited[i][j]=0;

           }
      }

      cout << mx;

      return 0;
}

void solve(int y, int x, int now){
     if(x<M-2){
          if(y!=N-1){
               mx=max(mx, map[y][x]+map[y][x+1]+map[y][x+2]+map[y+1][x+1]);
          }
          if(y!=0){
               mx=max(mx, map[y][x]+map[y][x+1]+map[y][x+2]+map[y-1][x+1]);
          }
     }
     if(y<N-2){
          if(x!=M-1){
               mx=max(mx, map[y][x]+map[y+1][x]+map[y+2][x]+map[y+1][x+1]);
          }
          if(x!=0){
               mx=max(mx, map[y][x]+map[y+1][x]+map[y+2][x]+map[y+1][x-1]);
          }
     }
     visited[y][x]=true;
     dfs(y, x, now, 1);
     visited[y][x]=false;
     return ;
}

void dfs(int y, int x, int now, int depth){
     if(depth==4){
          if(mx<now){
               mx=now;
          }
          return;
     }

     for(int i=0; i<4; i++){
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(ny>=0 && ny<N && nx >=0 && nx<M && !visited[ny][nx]){
               visited[ny][nx]=true;
               dfs(ny, nx, now+map[ny][nx], depth+1);
               visited[ny][nx]=false;
          }
     }
}
