//https://www.acmicpc.net/problem/2293
#include <iostream>
using namespace std;
int dp[10001];
int value[101];


int main()
{
     int n, k;
     cin >> n >> k;

     for(int i=0; i<n; i++) cin >> value[i];

     dp[0]=1;

     for(int i=0; i<n; i++){
          for(int j=1; j<=k; j++){
               if(j>=value[i]){
                    dp[j]+=dp[j-value[i]];
               }
          }
     }

     cout << dp[k];
}
