//https://www.acmicpc.net/problem/14502
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int map[8][8];
int secure[8][8];
bool visited[8][8];
bool visited2[8][8];
int N, M;
int mx;
int dy[4]={0,0,-1,1};
int dx[4]={-1,1,0,0};
int virus[10][2];
int num;
queue<pair<int , int> > q;
void input(){
     cin >> N >> M;

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               cin >> map[i][j];
               if(map[i][j]==2){
                    virus[num][0]=i;
                    virus[num++][1]=j;
               }
          }
     }
}

void solve(int y, int x, int wall){
     if(wall==3){
          //bfs로 안전영역 개수 확인
          for(int i=0; i<N; i++){
               for(int j=0; j<M; j++){
                    secure[i][j]=map[i][j];
               }
          }

          for(int i=0; i<num; i++){
               q.push(make_pair(virus[i][0],virus[i][1]));
          }

          while(!q.empty()){
               int nowy=q.front().first;
               int nowx=q.front().second;
               visited2[nowy][nowx]=1;
               q.pop();
               //cout <<q.size() <<endl;
               for(int i=0; i<4; i++){
                    int ny=nowy+dy[i];
                    int nx=nowx+dx[i];

                    if(secure[ny][nx]==0 && ny>=0 && ny<N && nx>=0 && nx<M && !visited2[ny][nx]){
                         secure[ny][nx]=2;
                         q.push(make_pair(ny, nx));
                         visited2[ny][nx]=1;
                    }
               }
          }

          int ans=0;
          for(int i=0; i<N; i++){
               for(int j=0; j<M; j++){
                    if(secure[i][j]==0) ans++;
                    visited2[i][j]=0;
               }
          }

          if(mx<ans) mx=ans;
          return;
     }

     for(int i=y; i<N; i++){
          for(int j=0; j<M; j++){
               if(map[i][j]==0 && !visited[i][j]){
                    visited[i][j]=1;
                    map[i][j]=1;
                    solve(i, j, wall+1);
                    map[i][j]=0;
                    visited[i][j]=0;
               }
          }
     }

     return;
}
int main(){
     input();

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               if(map[i][j]==0) {
                    visited[i][j]=1;
                    map[i][j]=1;
                    solve(i, j, 1);
                    map[i][j]=0;
                    visited[i][j]=0;
               }
          }
     }
     cout << mx;
}
