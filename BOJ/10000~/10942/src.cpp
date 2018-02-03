//https://www.acmicpc.net/problem/10942
#include <iostream>
#include <stdio.h>
using namespace std;
int num[2001];
bool dp[2001][2001];

 int main()
 {
      int n, m;
      int start, end;
      scanf("%d",&n);

      for(int i=1; i<=n; i++) scanf("%d",&num[i]);

     scanf("%d",&m);
     for(int i=1; i<=n; i++)
     {
          dp[i][i]=1;
          if(i!=n && num[i]==num[i+1]) dp[i][i+1]=1;
     }



     for(int i=2; i<=n; i++) // i start->end까지의 길이
     {
          for(int j=1 ; j<=n-i; j++)
          {
               if(dp[j+1][j+i-1] && num[j]==num[j+i])
               { dp[j][j+i]=1;}
          }
     }/*
     for(int i=1; i<=n; i++){
          for(int j=1; j<=n; j++) cout << dp[i][j] << " ";
          cout << endl;
     }*/

     for(int i=0; i<m; i++)
     {
          scanf("%d %d",&start,&end);
          printf("%d\n",dp[start][end]);
     }
}
