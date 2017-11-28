//https://www.acmicpc.net/problem/1495
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

bool dp[101][1001];

int V[101];

int main()
{
  int N, S, M;
  cin >> N >> S >> M;
  int x, y;
  for(int i=1; i<=N; i++) cin >> V[i];

  dp[0][S]=1;
  for(int i=1; i<=N; i++)
  {
    int x=pow(2,i);
    int a=0;
    for(int j=0; j<=M; j++)
    {
      if(dp[i-1][j])
      {
        if(j-V[i] >=0 && j-V[i]<=M) dp[i][j-V[i]]=1;
        else a++;
        if(j+V[i] >=0 && j+V[i]<=M) dp[i][j+V[i]]=1;
        else a++;
      }
      if(a==x){ cout << "-1"; return 0;}
    }
  }
  cout << "x  " ;
  for(int j=0; j <=M; j++) cout <<j <<"  ";
  cout << endl;
  for(int i=0; i<=N; i++)
  { cout << i << "  " ;
    for(int j=0; j <=M; j++)
    cout << dp[i][j] << "  ";
    cout << endl;
  }
  cout << "  DP " << endl;
  int max=-1;
  for(int j=0; j<=M; j++)
  {
    if(dp[N][j] && j>max) max=j;
 }
    cout << max;
}
