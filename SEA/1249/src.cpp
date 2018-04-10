#include <iostream>
#include <algorithm>
using namespace std;
char map[100][100];
int dp[100][100];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int N;

void init(){
     for(int i=0; i<100; i++)
          for(int j=0; j<100; j++){
               map[i][j]='0';
               dp[i][j]=0;
          }
}

void map_input(){
     for(int i=0; i<N; i++)
          cin >> map[i];
}

void dfs(int y, int x){
     if(dp[y][x]==0){
          dp[y][x]=map[y][x]-'0';

          int ny, nx;
          for(int i=0; i<4; i++){
               ny=y+dy[i];
               nx=x+dx[i];

               if(ny>=0 && ny<N && nx>=0 && nx<N)
               dp[y][x]=min(dp[y][x], dfs(ny,nx)+dp[ny][nx]);
          }
     }
}

int main(){
     int T;
     cin >> T;

     for(int tc=1; tc<=T; tc++){
          cin >> N;
          init();
          map_input();

          dfs(0,0);
     }
}
