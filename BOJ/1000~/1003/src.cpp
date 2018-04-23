//https://www.acmicpc.net/problem/1003
#include <iostream>
using namespace std;

int dp[41][2];
int main(){
     int n;
     cin >> n;
     dp[0][0]=1;
     dp[1][1]=1;

     for(int i=2; i<=40; i++){
          for(int j=0; j<2; j++){
               dp[i][j]=dp[i-2][j]+dp[i-1][j];
          }
     }

     for(int i=0; i<n; i++) {
          int k;
          cin >> k;
          cout << dp[k][0] << " " << dp[k][1]<<endl;
     }
     return 0;
}
