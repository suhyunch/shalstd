//https://www.acmicpc.net/problem/12100
#include <iostream>
using namespace std;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
int mx=0;
int N;
int board[20][20][2];
int cache[6][20][20];
void solve(int dir, int depth);

int main(){
     cin >> N;
     for(int i=0; i<N; i++)
          for(int j=0; j<N; j++){
               cin >> board[i][j][0];
               cache[0][i][j]=board[i][j][0];
          }



     for(int i=0; i<4; i++){
          solve(i, 0);
          for(int a=0; a<N; a++)
               for(int j=0; j<N; j++){
                    board[a][j][0]=cache[0][a][j];
               }

     }
     cout << mx;
}

void solve(int dir, int depth){
     if(depth==5) {
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    if(board[i][j][0]>mx)
                         mx=board[i][j][0];
                    }
               }

          return;
     }



     if(dir==UP){
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    if(board[i][j][0]==0) continue;
                    for(int k=i-1; k>=0; k--){
                         if(board[k][j][0]==0) {
                              board[k][j][0]=board[k+1][j][0];
                              board[k+1][j][0]=board[k+1][j][1]=0;
                         }
                         else if(board[k][j][0]==board[k+1][j][0] && !board[k][j][1] && !board[k+1][j][1]){
                              board[k][j][0]*=2;
                              board[k+1][j][0]=0;
                              board[k][j][1]=1;
                         }
                    }
               }
          }
     }
     if(dir==DOWN){
          for(int i=N-1; i>=0; i--){
               for(int j=N-1; j>=0; j--){
                    if(board[i][j][0]==0) continue;
                    for(int k=i+1; k<N; k++){
                         if(board[k][j][0]==0) {
                              board[k][j][0]=board[k-1][j][0];
                              board[k-1][j][0]=board[k-1][j][1]=0;
                         }
                         else if(board[k][j][0]==board[k-1][j][0] && !board[k][j][1] && !board[k-1][j][1]){
                              board[k][j][0]*=2;
                              board[k-1][j][0]=0;
                              board[k][j][1]=1;
                         }
                    }
               }
          }
     }
     if(dir==LEFT){
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    if(board[i][j][0]==0) continue;
                    for(int k=j-1; k>=0; k--){
                         if(board[i][k][0]==0) {
                              board[i][k][0]=board[i][k+1][0];
                              board[i][k+1][0]=board[i][k+1][1]=0;
                         }
                         else if(board[i][k][0]==board[i][k+1][0] && !board[i][k][1] && !board[i][k+1][1]){
                              board[i][k][0]*=2;
                              board[i][k+1][0]=0;
                              board[i][k][1]=1;
                         }
                    }
               }
          }
     }
     if(dir==RIGHT){
          for(int i=0; i<N; i++){
               for(int j=N-1; j>=0; j--){
                    if(board[i][j][0]==0) continue;
                    for(int k=j+1; k<N; k++){
                         if(board[i][k][0]==0) {
                              board[i][k][0]=board[i][k-1][0];
                              board[i][k-1][0]=board[i][k-1][1]=0;
                         }
                         else if(board[i][k][0]==board[i][k-1][0] && !board[i][k][1] && !board[i][k-1][1]){
                              board[i][k][0]*=2;
                              board[i][k-1][0]=0;
                              board[i][k][1]=1;
                         }
                    }
               }
          }
     }
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               cache[depth+1][i][j]=board[i][j][0];
               board[i][j][1]=0;
          }
     }

     for(int i=0; i<4; i++){
          solve(i, depth+1);
          for(int j=0; j<N; j++){
               for(int k=0; k<N; k++){
                    board[j][k][0]=cache[depth+1][j][k];
               }
          }
     }
}
