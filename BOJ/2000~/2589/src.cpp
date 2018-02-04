//https://www.acmicpc.net/problem/2589
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
char map[50][50];
int visited[50][50];
int N,M, mx;

int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void init(){
     for(int i=0; i<N; i++)
          for(int j=0; j<M; j++)
               visited[i][j]=0;
}

void bfs(int y, int x){
     queue< pair<int, int> > q;
     q.push(make_pair(y,x));

     visited[y][x]=1;
     while(!q.empty()){
          y=q.front().first;
          x=q.front().second;
          q.pop();

          for(int i=0; i<4; i++){
               int ny=y+dy[i];
               int nx=x+dx[i];

               if(ny>=0 && ny<N && nx>=0 && nx<M){
                    if(map[ny][nx]=='L' && !visited[ny][nx]){
                         q.push(make_pair(ny,nx));
                         visited[ny][nx]=visited[y][x]+1;
                         if(visited[ny][nx]>mx) mx=visited[ny][nx];
                    }
               }
          }
     }
}

int main(){
     cin >> N >> M;

     for(int i=0; i<N; i++)
          cin >> map[i];

     for(int i=0; i<N; i++)
          for(int j=0; j<M; j++){
               if(map[i][j]=='L'){
                    init();
                    bfs(i,j);
               }
          }

     cout << mx-1;
}
