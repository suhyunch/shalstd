//https://www.acmicpc.net/problem/3933
#include <iostream>
#include <cmath>
using namespace std;
int dp[sizeof(int)][5];
int main(){
     int n=0;
     int tmp;
     while(1){
          tmp=n;
          cin >> n;
          if(n==0) break;

          for(int i=tmp+1; i<=n; i++)
               if(sqrt(i)*sqrt(i)==i){
                    dp[i][1]=1;
               }
          dp[1][1]=1;
          dp[2][2]=1;
          dp[3][3]=1;
          dp[4][4]=1;
          for(int i=tmp+1; i<=n; i++){
               if(i<5) continue;
               for(int a=1; 2*a<i; a++){
                    for(int j=1; j<=4; j++){
                         for(int k=1; k<=4; k++){
                              if(j+k<5 && dp[a][j] && dp[i-a][k]){
                                   cout << a << " " << j <<" "<< k <<endl;
                                   if(dp[a][j]+dp[i-a][k]) dp[i][j+k]++;                                   
                              }
                         }
                    }
               }
          }

          for(int i=1; i<=n; i++){
               for(int j=1; j<=4; j++){
                    cout << dp[i][j] << " ";
               }
               cout <<endl;
          }
          int ans=0;
          for(int i=1; i<=4; i++)
               ans+=dp[n][i];

          cout << ans <<endl;
     }
}
