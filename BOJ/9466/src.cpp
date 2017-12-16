//https://www.acmicpc.net/problem/9466
#include <iostream>
using namespace std;

int pick[100001];
bool visit[100001];
bool chker[100001];
int cnt;
int n;

void chk(int x)
{
     int nn=x;
     while(1)
     {
          chker[nn]=1;
          nn=pick[nn];
          if(nn==x) break;
     }
}

void dfs(int start, int i)
{
     visit[i]=1;
     while(1)
     {
          int nn=pick[i];
          if(visit[nn] && nn == start) {
               chk(start);
               break;}

          if(!visit[nn]) dfs(start, nn);
          else break;
     }
}
int main()
{
     int T;
     cin >> T;

     for(int TC=0; TC<T; TC++)
     {
          cin >> n;

          cnt=0;

          for(int i=1; i<=n; i++)
          {
               cin >> pick[i];
               visit[i]=0;
          }

          for(int i=1; i<=n; i++)
          {
               if(!chker[i]) dfs(i,i);
          }
          for(int i=1; i<=n; i++) if(!chker[i]) cnt++;

          cout << cnt << endl;
     }
}
