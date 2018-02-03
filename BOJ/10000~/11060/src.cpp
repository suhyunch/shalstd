//https://www.acmicpc.net/problem/11060
#include <iostream>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int A[1001];
  int dp[1001];
  int min;
  for(int i=1; i<=N; i++) cin >> A[i];

  dp[1]=0;
  for(int i=2; i<=N; i++)
  {
    min=1001;
    for(int j=i-1; j>0; j--)
    {
      if(i-j==101) break;
      if(j+A[j]>=i && dp[j]!=-1)
        if(min>dp[j]+1) min=dp[j]+1;
    }
    if(min==1001) dp[i]=-1;
    else dp[i]=min;
  }

  cout << dp[N];
}
