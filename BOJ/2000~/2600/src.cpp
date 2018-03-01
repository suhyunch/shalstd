//https://www.acmicpc.net/problem/2600
#include <iostream>
using namespace std;
bool dp[501][501];
int b[3];
int k[2][5];
void find_dp(){
     for(int i=0; i<=500; i++){
          for(int j=0; j<=500; j++){
               dp[i][j]=0;
               for(int k=0; k<3; k++){
                    if(i-b[k]>=0 && dp[i-b[k]][j]==0)
                         dp[i][j]=1;
                    if(j-b[k]>=0 && dp[i][j-b[k]]==0)
                         dp[i][j]=1;
               }
          }
     }
}
int main(){

     cin >> b[0] >> b[1] >> b[2] ;

     find_dp();
     for(int i=0; i<5; i++){
          cin >> k[0][i] >> k[1][i];
     }
     for(int i=0; i<5; i++){
          if(dp[k[0][i]][k[1][i]]) cout << "A" << endl;
          else cout << "B" <<endl;
     }
}
