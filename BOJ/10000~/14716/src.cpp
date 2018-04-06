//https://www.acmicpc.net/problem/14716
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool map[250][250];
//bool visited[250][250];

int N, M;
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};

void input();
void bfs(int y, int x);

int main(){
     int ans=0;
     input();
     for(int i=0; i<M; i++){
          for(int j=0; j<N; j++){
               if(map[i][j]){
                    bfs(i, j);
                    ans++;
               }
          }
     }

     cout << ans;
}

void input(){
     cin>> M>>N;

     for(int i=0; i<M; i++){
          for(int j=0; j<N; j++){
               cin >> map[i][j];
          }
     }
}

void bfs(int y, int x){
     queue<pair <int, int> > q;
     q.push(make_pair(y, x));
     map[y][x]=0;

     while(!q.empty()){
          int nowy=q.front().first;
          int nowx=q.front().second;
          q.pop();

          for(int i=0; i<8; i++){
               int ny=nowy+dy[i];
               int nx=nowx+dx[i];
               if(map[ny][nx] && ny>=0 &&ny<M && nx>=0 && nx<N){
                    q.push(make_pair(ny, nx));
                    map[ny][nx]=0;
               }
          }
     }
     return;
}
