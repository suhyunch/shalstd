#include <iostream>
using namespace std;
int ingredient[16][16];
int N;
bool match[16];// 0은 A, 1은 B
int mn=1e9;

int abs(int a, int b) {return a>b ? a-b : b-a;}
void init();
void input();
void dfs(int depth, int cnt);
void solve();
int main(){
     int tc;
     scanf("%d",&tc);

     for(int T=1; T<=tc; T++){
          init();
          input();

          dfs(0, 0);

          printf("#%d %d\n", T, mn);
     }
}

void init(){
     for(int i=0; i<16; i++){
          match[i]=false;
          for(int j=i; j<16; j++){
               ingredient[i][j]=0;
          }
     }
     mn=1e9;
     return;
}
void input(){
     scanf("%d", &N);

     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               int a;
               scanf("%d", &a);

               if(ingredient[j][i]==0)
                    ingredient[i][j]=a;
               else ingredient[j][i]+=a;
          }
     }
     return;
}
void dfs(int depth, int cnt){
     if(cnt>N/2) return;
     if(depth==N){
          if(cnt!=N/2) return;
          solve();
          return;
     }

     for(int i=0; i<2; i++){
          match[depth]=i;
          dfs(depth+1, i==1 ? cnt+1 : cnt);
     }
}
void solve(){
     int A=0, B=0;

     for(int i=0; i<N; i++){
          if(match[i]){ // 식재료 i가 B요리사
               for(int j=i; j<N; j++){
                    if(match[j]){
                         B+=ingredient[i][j];
                    }
               }
          }
          else{ // 식재료 i가 A요리사
               for(int j=i; j<N; j++){
                    if(!match[j]){
                         A+=ingredient[i][j];
                    }
               }
          }
     }

     if(mn > abs(A, B)) mn=abs(A,B);
     return;
}
