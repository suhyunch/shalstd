//https://www.acmicpc.net/problem/1563
#include <iostream>
#define mod 1000000
using namespace std;
int dp[1001][2][3];
int N;

int find(int today, int late, int absence){
     if(today==N) return 1;
     if(dp[today][late][absence]) return dp[today][late][absence];

     //오늘 지각한 경우
     if(late==0){
          dp[today][late][absence]+=find(today+1, late+1, 0);
          dp[today][late][absence]%=mod;
     }

     //연속 결속 0일, 1일인 경우 결석
     if(absence<2){
          dp[today][late][absence]+=find(today+1, late, absence+1);
          dp[today][late][absence]%=mod;
     }

     //오늘 출석한 경우
     dp[today][late][absence]+=find(today+1, late, 0);
     dp[today][late][absence]%=mod;

     return dp[today][late][absence];


}
int main(){
      cin >> N;

      cout << find(0,0,0);
}
