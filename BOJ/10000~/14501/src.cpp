//https://www.acmicpc.net/problem/14501
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int counsel[16][2];
int dp[16];

void input();
void solve(int today, int earn);

int main(){

     cin >> N;

     input();

     solve(counsel[1][0], counsel[1][1]);
     solve(1, 0);
     cout << dp[N];
     return 0;
}

void input(){
     for(int i=1; i<=N; i++)
          cin >> counsel[i][0] >> counsel[i][1];
}

void solve(int today, int earn){
     if(today<=N){
          dp[today]=max(dp[today],earn);
     }
     if(today>=N){
          return;
     }

     if(today+counsel[today+1][0]<=N){
          solve(today+counsel[today+1][0], earn+counsel[today+1][1]);
     }
     solve(today+1, earn);
}
