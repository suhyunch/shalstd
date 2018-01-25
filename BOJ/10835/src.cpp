//https://www.acmicpc.net/problem/10835
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[2001][2001];
 // dp[x][y] : 왼쪽카드x번째, 오른쪽카드 y번째일 때, 앞으로 얻을 수 있는 점수 최대값
int lc[2001]; // left card
int rc[2001]; // right card
int n;

int play(int x, int y)
{
     if(x==n+1 || y==n+1) return 0;// 둘 중 하나가 더이상 카드가 없으면 앞으로 얻을 점수 0

     if(dp[x][y] != -1) return dp[x][y]; // 이미 계산한 것은 나와야함

     // 앞으로 얻을 점수이므로 앞에서와는 무관하고 변하지않음!!!
     //계산은 한 번이면 됨!
     dp[x][y]=max(play(x+1,y), play(x+1,y+1));
     //dp[x][y]는 왼쪽카드를 하나 버리거나, 둘 다 버렸을 때 둘 중 하나의 최대값
     if(lc[x]>rc[y]) // 현재 카드 중 오른쪽 카드가 더 작으면 점수+,오른쪽만 버림.
          dp[x][y]=max(dp[x][y], play(x,y+1)+rc[y]);

     return dp[x][y];
}

int main()
{
     memset(dp,-1,sizeof(dp));
     scanf("%d",&n);

     for(int i=1; i<=n; i++) scanf("%d",&lc[i]);
     for(int i=1; i<=n; i++) scanf("%d",&rc[i]);

     int ans = play(1,1);//왼쪽카드 1, 오른쪽카드 1, 앞으로 얻을 수 있는 점수 최대값 :: 시작지점.
     printf("%d",ans);
}
