#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int N, K;

int bfs(void)
{
    queue< pair<int, int> >  q;
    bool visit[100001]={0};
    q.push({N,0});
    while(!q.empty())
    {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        if(x<0 || x>100000) continue;
        if(visit[x]) continue;

         visit[x]=1;
        if(x==K) return t;

        q.push({x*2,t+1});
        q.push({x+1,t+1});
        q.push({x-1,t+1});
        }
}

int main()
{
    scanf("%d %d", &N, &K);
    printf("%d", bfs());
    return 0;
}
