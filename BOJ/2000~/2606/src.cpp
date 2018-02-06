//https://www.acmicpc.net/problem/2606
#include <iostream>
#include <queue>
using namespace std;
int N, M, cnt;
bool network[101][101];
bool visited[101];

void input(){
     cin >> N >> M;

     int a,b;
     for(int i=0; i<M; i++){
          cin >> a >> b;
          network[a][b]=network[b][a]=1;
     }
}

void bfs(){
     queue<int> q;
     q.push(1);
     visited[1]=1;

     while(!q.empty()){
          int now=q.front();
          q.pop();

          for(int i=2; i<=N; i++){
               if(network[now][i] && !visited[i]){
                    q.push(i);
                    visited[i]=1;
                    cnt++;
               }
          }
     }
}

int main(){

     input();

     bfs();

     cout << cnt;
}
