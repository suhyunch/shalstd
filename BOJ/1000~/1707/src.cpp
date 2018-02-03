//https://www.acmicpc.net/problem/1707
#include <iostream>
using namespace std;
bool graph[20001][20001];
int visited[20001];
int v, e;

bool dfs(int now, int c)
{

     visited[now]=c;
     for(int i=1; i<=v; i++)
     {
          if(visited[graph[now][i]]==c) return 0;
          if(graph[now][i] && visited[i]==-1)
          {
               dfs(i,(~c)+1);
          }
     }
     return 1;
}

int main()
{
     int k;
     bool chk=1;
     cin >> k;
     for(int i=0; i<k; i++)
     {
          for(int j=0; j<=v; j++) visited[j]=-1;
          cin >> v >> e;

          for(int j=1; j<=e; j++)
          {
               int a,b;

               cin >> a >> b;
               graph[a][b]=graph[b][a]=1;
          }

          for(int j=1; j<=v; j++)
          {
               if(visited[j]==-1)
               {
                    if(!dfs(j,0))
                    {
                         chk=0;
                         break;
                    }
               }
          }

          if(chk) cout << "YES" << endl;
          else cout << "NO" << endl;
     }
}
