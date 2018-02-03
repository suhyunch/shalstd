//https://www.acmicpc.net/problem/2294
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10001];
int value[101];


int main()
{
     int n, k;
     cin >> n >> k;

     for(int i=0; i<n; i++) cin >> value[i];

     dp[0]=0;
     dp[value[0]]=1;

     for(int i=0; i<n; i++) dp[value[i]]=1;
     for(int i=value[0]+1; i<=k; i++){
          dp[i]=dp[i-value[0]]+1;
     }

     for(int i=1; i<n; i++){
          for(int j=1; j<=k; j++){
               if(j>value[i]){

                    dp[j]=min(dp[j-value[i]], dp[j]);
               }
          }
     }

     cout << dp[k];
}
