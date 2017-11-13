#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int visit[1001];
bool graph[1001][1001];
int N,M,V;


void BFS(int curr)
{
    queue<int> q;
    q.push(curr);
    if(visit[curr]) return;

    while(!q.empty())
    {
        curr = q.front();
        if(visit[curr]==0)  printf("%d ",curr);
        visit[curr]=1;
        q.pop();
        for(int i=1; i<=N; i++)
            if(graph[curr][i]==1 && visit[i]==0)
                  q.push(i);
      }
}

void DFS(int curr)
{
    if(visit[curr]==0) printf("%d ",curr);
    visit[curr]=1;
    for(int i= 1; i<=N; i++)
        if(graph[curr][i]==1 && visit[i]==0) DFS(i);
}

int main()
{
    int m, start;
    int one, two;

    scanf("%d %d %d", &N, &m, &start);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &one, &two);

        graph[one][two] = graph[two][one] = 1;
    }

    DFS(start);
    printf("\n");
    for(int i=1; i<=N; i++) visit[i]=0;
    BFS(start);

}
