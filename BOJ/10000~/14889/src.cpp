//https://www.acmicpc.net/problem/14889
#include <iostream>
using namespace std;
int S[21][21];
int combinations[10];
int combinationl[10];
bool visit[11];
int n;

int dfs(int start, int cnt)
{
     combinations[cnt]=start;
     visit[start]=1;

     if(cnt==n/2)
     {
          int teams=0;
          int teaml=0;

          for(int i=0; i<cnt; i++)
          {
               if((i+1)==combinations[i]
          }
          for(int i=0; i<cnt; i++)
          {
               int row=combinations[i];
               for(int j=0; j<cnt; j++)
               {
                    if(i==j) continue;
                    int col=combinations[j];
                    teams+=S[row]S[col];

               }
          }
          return 0;
     }

     int now=start;
     for(int i=start; ;i++)
     {
          int nn=now+1;
          if(!visit[nn] && nn<=n)
          {
               dfs(nn, cnt++);

          }
     }
     visit[start]=0;
}


 int main()
 {

      cin >> n;

      for(int i=1; i<=n; i++)
           for(int j=1; j<=n; j++)
                cin >> S[i][j];

      int min=100000000;
      for(int i=1; i<=n/2+1; i++)
          dfs(i, 1);//시작위치, 현재 탐색 깊이

      cout << min;

}
