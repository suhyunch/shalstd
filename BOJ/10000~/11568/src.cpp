//https://www.acmicpc.net/problem/11568
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int num[1001];

int main(){
     int N;
     int mx=1;
     cin >> N;

     for(int i=1; i<=N; i++) cin >> num[i];

     dp[1]=1;

     for(int i=2; i<=N; i++){
          for(int j=i; j>=0; j--){
               if(num[j]<num[i]){
                    dp[i]=max(dp[i],dp[j]+1);
               }
          }
          mx=max(mx,dp[i]);
     }

     cout << mx;
}
