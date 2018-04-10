#include <iostream>
#include <queue>
using namespace std;
bool adj[101][101];
int visit[101];
int chk[100];
int start, max3;

int bfs(int t)
{
     queue<int> q;
     q.push(start);
     int max2=0;
     visit[start]=1;

     while(!q.empty())
     {
          int n=q.front();
          q.pop();

          for(int i=1; i<=max3; i++)
          {
               if(adj[n][i] && visit[i]==0)
               {
                    q.push(i);
                    visit[i]=visit[n]+1;
                    if(max2 < visit[i]) max2=visit[i];
               }
          }
     }
     cout << " maxvisit "<< max2 <<endl;
     return max2;
}

int max1(int a, int b)
{ return a>b? a : b;}

int main()
{
     for(int t=1; t<=10; t++)
     {
          for(int i=1; i<=101; i++)
               for(int j=1; j<=101; j++) adj[i][j]=0;
          for(int i=1; i<=101;i++) visit[i]=0;

          int n;
          int from, to;
          cin >> n >> start;

          max3=0;
          for(int i=1; i<=n/2; i++)
          {
               cin >> from >> to;
               adj[from][to]=1;

               if(max3 < max1(from, to)) max3= max1(from, to);
          }
for(int i=1; i<=max3; i++) cout << visit[i] <<" ";
cout << endl;
          int x=bfs(start);

          cout << x <<endl;
          for(int i=1; i<=max3; i++) cout << i <<" :: "<< visit[i] <<endl;
          cout << endl;
          int mx=0;
          for(int i=1; i<=max3; i++){
               if(visit[i]==x) mx=i;
          }
		 cout << "#" << t << " " << mx << endl;
     }
}
