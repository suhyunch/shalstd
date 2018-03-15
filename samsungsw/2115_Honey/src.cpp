#include <iostream>
using namespace std;
int N,M,C;
int honey[10][10];
int profit[10][10];
bool visited[10];
//int mx,
int mx2;
void init(){
     for(int i=0; i<10; i++){
          for(int j=0; j<10; j++){
               honey[i][j]=profit[i][j]=0;
          }
     }
     mx2=0;
     return;
}

void input(){
     cin >> N >> M >> C;

     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               cin >> honey[i][j];
          }
     }
     return;
}
int dfs(int y, int x, int num_honey, int cost, int depth){
     //printf("y : %d, x :  %d, nh : %d, cost : %d, depth : %d\n", y,x, num_honey, cost, depth);
     if(depth>=M) return cost;
     int ncost;
     int mx=0;
     for(int i=depth; i<M; i++){
          if(num_honey+honey[y][x+i] <= C){
               ncost=dfs(y, x, num_honey+honey[y][x+i], cost+honey[y][x+i]*honey[y][x+i], i+1);
               if(mx<ncost) mx=ncost;
          }
          ncost=dfs(y, x, num_honey, cost, i+1);
          if(mx < ncost) mx=ncost;
     }
     return mx;
}

void find(int y, int x){
     int cost1=profit[y][x];
     for(int i=y; i<N; i++){
          for(int j=0; j<N; j++){
               if(i==y && j<x+M) continue;
               if(mx2<cost1+profit[i][j]) {
                    mx2= cost1+profit[i][j];
               }
          }
     }
}

int main(){
     int tc;
     cin >>tc;

     for(int T=1; T<=tc; T++){
          init();
          input();


          for(int i=0; i<N; i++){
               for(int j=0; j<=N-M; j++){
                    profit[i][j]=dfs(i,j,0, 0, 0);
               }
          }

          cout <<endl;
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    cout << profit[i][j] <<" ";
               }cout << endl;
          }
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    find(i,j);
               }
          }

          cout << "#" << T << " " << mx2 <<endl;
     }
}
