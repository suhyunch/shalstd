//https://www.acmicpc.net/problem/10451
#include <iostream>
using namespace std;
int graph[1001];
bool visited[1001];
int n;

void init(){
     for(int i=0; i<=n; i++)
          graph[i]=visited[i]=0;
}

void input(){
     cin >> n;
     for(int i=1; i<=n; i++)
          cin >> graph[i];
}

void dfs(int now){
     visited[now]=1;
     int next=graph[now];

     if(!visited[next]) dfs(next);
}
int main(){
      int t;

      cin >> t;

      while(t-->0){
           init();
           input();

           int ans=0;
           for(int i=1; i<=n; i++){
                if(!visited[i]){
                     dfs(i);
                     ans++;
                }
           }
           cout << ans << endl;
      }
}
