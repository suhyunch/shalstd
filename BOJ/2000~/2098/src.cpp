//https://www.acmicpc.net/problem/2098
#include <iostream>
#define MAX 17000000
using namespace std;

int w[16][16];
int dp[1<<16][16];
//visited[i][j]
//i는 이미 방문한 도시들의 집합, j는 현재 도시
//방문하지않은 나머지 도시들을 모두 방문한 뒤 출발 도시로 돌아올 때 드는 최소비용
int start;
int N;

int solve(int visited, int now);
int main(){
     cin >>N;
     for(int i=0; i<N; i++)
          for(int j=0; j<N; j++)
               cin >>w[i][j];

     int ans = solve(0,0);

     cout << ans;
     return 0;
}

int solve(int visit, int now){
     //now번째 도시 방문
     visit |= (1<<now);

     //모든 도시를 지난 경우
     if( visit == (1<<N)-1 ){
          if(w[now][0]>0){
               return w[now][0];
          }
          return MAX;
     }

     int& ret=dp[visit][now];
     //dp[visit][now]가 이미 들렀다면 return
     if(ret>0) return ret;

     ret=MAX;
     for(int i=0; i<N; i++){
          if(i!=now && (visit&(1<<i))==0 && w[now][i]>0){
               //i가 나우가 아니고, i번 도시를 아직 들리지 않았고
               //현재 도시에서 i로 가는길이 있는 경우
               int tmp=solve(visit, i) +w[now][i];
               if(ret>tmp) ret = tmp;
          }
     }
     return ret;
}
