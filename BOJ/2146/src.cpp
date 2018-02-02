//https://www.acmicpc.net/problem/2146
#include <iostream>
#include <queue>
using namespace std;
bool map[100][100];
int visited[100][100];
int visited2[100][100];
bool visitl[10001];
int N, cnt;
int min1=10001;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void dfs(int y, int x, int land){
     visited[y][x]=land;

     for(int i=0; i<4; i++){
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && map[ny][nx]){
               dfs(ny, nx, land);
          }
     }
}

void bfs(int land){
     queue<int> q;

     //섬의 테두리 옆의 다리값을 1로 지정 & 다리 시작점 q에 넣음
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               if(visited[i][j]==land){
                    for(int k=0; k<4; k++){
                         int ny=i+dy[k];
                         int nx=j+dx[k];

                         if(ny>=0 && ny<N && nx>=0 && nx<N){
                              if(!map[ny][nx]){
                                   q.push(ny*100+nx);
                                   visited2[ny][nx]=1;
                              }
                         }
                    }
               }
          }
     }

     while(!q.empty()){
          int nowy=q.front()/100;
          int nowx=q.front()%100;
          q.pop();

          for(int i=0; i<4; i++){
               int ny=nowy+dy[i];
               int nx=nowx+dx[i];

               if(ny>=0 && ny<N && nx>=0 && nx<N){
                    if(visited[ny][nx] != land && visited[ny][nx]>0){
                         if(visited2[nowy][nowx]<min1){
                              min1=visited2[nowy][nowx];
                         }
                         return;
                    }

                    if(!map[ny][nx] && !visited2[ny][nx]) {
                         q.push(ny*100+nx);
                         visited2[ny][nx]=visited2[nowy][nowx]+1;
                    }
               }
          }
     }
}

int main(){
     cin >> N;

     for(int i=0; i<N; i++)
          for(int j=0; j<N; j++)
               cin >> map[i][j];

     for(int i=0; i<N; i++)
          for(int j=0; j<N; j++)
               if(visited[i][j]==0 && map[i][j]==1){
                    cnt++;
                    dfs(i,j,cnt);
               }

     for(int i=1; i<cnt; i++)
          bfs(i);

     cout << min1;
}
