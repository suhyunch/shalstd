#include <iostream>
#include <queue>
using namespace std;
bool adj[101][101];
bool visit[101];
int start, max3;

void bfs(int t)
{
     queue<int> q;
     q.push(start);
     int max2;

     while(!q.empty())
     {
          int n=q.front();
          if(max2 < n) max2=n;
          q.pop();
          visit[n]=1;

          cout << n << endl;
          for(int i=1; i<=max3; i++)
          {
               max2=0;
               if(adj[n][i] && !visit[i])
               {    cout << "   "<<i << endl;
                    q.push(i);
                    if(max2 < i) max2=i;
               }
          }
     }
     cout << "#" << t << " " << max2 << endl;
}
int max1(int a, int b)
{ return a>b? a : b;}

int main()
{
     for(int t=1; t<=10; t++)
     {
          adj[101][101]={0,};
          for(int i=1; i<=101;i++) visit[i]=0;

          int n;
          int from, to;
          cin >> n >> start;

             cout <<"start :: "<< start << endl;

          max3=0;
          for(int i=1; i<=n/2; i++)
          {
               cin >> from >> to;

               cout <<"from :: "  << from << " to :: "  << to << endl;
               adj[from][to]=1;

               if(max3 < max1(from, to)) max3= max1(from, to);
          }

          bfs(t);

     }
}
