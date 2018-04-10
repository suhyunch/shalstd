//https://www.acmicpc.net/problem/1450
#include <iostream>
using namespace std;

int ans;
int w[30];
int N, C;
void dfs(int idx, int weight);
int main(){
      cin >> N >> C;

      for(int i=0; i<N; i++)
           cin >> w[i];

      for(int i=0; i<N; i++){
           dfs(i, w[i]);
           dfs(i, 0);
      }
     cout << ans;
}

void dfs(int idx, int weight){
     if(idx==N-1){
          if(weight<=C) ans++;
          cout << weight<<endl;
          return;
     }

     for(int i=idx; i<N; i++){
          dfs(i+1, weight+w[i]);
          dfs(i+1, weight);
     }
}
