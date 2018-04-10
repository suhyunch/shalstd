//https://www.acmicpc.net/problem/2206
#include <iostream>
using namespace std;
bool map[1001][1001];
bool visited[1001][1001];
int N, M;
int mn;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void dfs(int y, int x, bool wall, int l){
     if(y==N && x==M){
          if(mn>l) mn=l;
          return;
     }

     for(int i=0; i<4; i++){
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(!map[ny][nx] && !visited[ny][nx]){
               dfs(ny, nx, wall, l+1);
               if(wall==0) dfs(ny, nx, wall+1, l+1);
          }
     }
}
int main(){
     cin >> N >> M;

     for(int i=1; i<=N; i++){
          for(int j=1; j<=M; j++){
               cin >> map[i][j];
          }
     }

     mn=N*M;
     dfs(1,1,0,1);
}
