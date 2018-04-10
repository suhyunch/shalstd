#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
//dp[i][j]= 1~i번째 수열까지 j보다 큰수

int main(){
    int tc;
    cin >> tc;

    for(int T=1; T<=tc; T++){
        int N;
        cin >> N;
        long long int mx=0;
        queue<int> q;
        for(int i=1; i<=N; i++){
             int x;
             cin >> x;
             q.push(x);
             if(mx<x)  mx=x;
        }


        int **dp=new int*[N+1];
        for(int i=0; i<=mx; i++){
             dp[i]=new int[mx];
             memset(dp[i],0,sizeof(int)*(mx+1));
        }
        for(int i=1; i<=N; i++){
             int x=q.front();
             q.pop();
             for(int j=1; j<=mx; j++) {
                  if(j<x) dp[i][j]=dp[i-1][j]+1;
                  else dp[i][j]=dp[i-1][j];
             }
        }

        for(int i=1; i<=N; i++){
             for(int j=1; j<=mx; j++){
                  cout << dp[i][j] << " ";
             }cout <<endl;
        }

        int Q;
        cin >> Q;

        cout << "#" << T << endl;
        while(Q-->0){
            long long int L,R,K;
            cin >> L >> R >> K;

            cout << " " << dp[R][K]-dp[L-1][K] << endl;


        }
        cout << endl;
    }
    return 0;
}
