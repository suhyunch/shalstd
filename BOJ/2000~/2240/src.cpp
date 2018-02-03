//https://www.acmicpc.net/problem/2240
#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][31];
int plum[1001];

int main()
{
      int t,w;
      cin >> t >> w;

      for(int i=1; i<=t; i++)
          cin >> plum[i];//위치

     for(int i=1; i<=t; i++)
     {
          for(int j=1; j<=w; j++)
          {
               if(i<j) break;
               //dp[i][j]=i초에 j번 이동했을 때 최대 자두 개수
               //i초 동안 이동할 수 있는 횟수 j는 i보다 작다

               


          }
     }
}
