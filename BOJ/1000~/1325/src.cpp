//https://www.acmicpc.net/problem/1325
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, mx;
bool com[10001][10001];
int com_can[10001];
int tmp_depth[10001];
bool visited[10001];

int max(int a, int b)
{ return a>b ? a:b; }

void input(){
     cin >> N >> M;

     for(int i=1; i<=M; i++){
          int a,b;
          cin >> a >> b;

          com[a][b]=com[b][a]=1;
     }
}

void dfs(int now, int depth){
     visited[now]=1;
     tmp_depth[depth-1]=now;


     if(mx<depth){
          mx=depth;
          for(int i=0; i<depth; i++){
               com_can[i]=tmp_depth[i];
               cout << com_can[i] << endl;
          }
     }

     for(int i=1; i<=N; i++){
          int next=now+i;

          if(com[now][next] && !visited[next]){
               dfs(next,depth++);
          }
     }
}

void init_tmp(){
     for(int i=0; i<=N; i++){
          tmp_depth[i]=0;
          visited[i]=0;
     }
}

int main(){
     input();

     for(int i=1; i<=N; i++){
          init_tmp();
          dfs(i,1);
     }

     sort(com_can, com_can+mx);

     for(int i=0; i<mx; i++) cout << com_can[i] << " ";
}
