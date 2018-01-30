//https://www.acmicpc.net/problem/2644
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int parent[101]; // parent[i] :: i의 부모
int chon[101];
int n;

void bfs(int start)
{
     queue<int> q;
     q.push(start);
     chon[start]=0;

     while(!q.empty())
     {
          int now=q.front();
          q.pop();

          for(int i=1; i<=n; i++){
               if(parent[i]==now && chon[i] ==-1){
                    q.push(i);
                    chon[i]=chon[now]+1;
               }
          }

          if(parent[now]!=0 && chon[parent[now]] ==-1)
           {q.push(parent[now]); chon[parent[now]]=chon[now]+1;}
     }
}

int main()
{
     int a, b, m;
     cin >> n >> a >> b >> m;



     for(int i=0; i<m; i++){
          int x, y;
          cin >> x >> y;
          parent[y]=x;//y의 부모가 x
     }

     memset(chon, -1, sizeof(chon));

     bfs(a);

     cout << chon[b];
}
