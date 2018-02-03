//https://www.acmicpc.net/problem/1010
#include <iostream>
using namespace std;
int dp[31][31];

int main(){
     int t;
     cin >> t;

     while(t-->0){
          int n, m;
          cin >> n >> m;

          for(int i=1; i<=m; i++) dp[1][i]=i;

          for(int i=2; i<=n; i++){
               for(int j=i; j<=m; j++){
                    if(dp[i][j]) continue;
                    for(int k=j; k>=i; k--)
                    dp[i][j]+=dp[i-1][k-1];

                    cout <<"i : " <<i <<", j : " << j<< " -- "  <<dp[i][j] << endl;
               }
          }

          cout << dp[n][m] <<endl;
     }
}
