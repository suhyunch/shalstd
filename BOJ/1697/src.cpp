#include <iostream>
#include <queue>
using namespace std;
int N, K,t;
bool visit[100000];

int dfs(int x, int t)
{
    visit[x]=1;
    if(x==K) return;
    int mint=0;
    if(!visit[x-1] && x+1<=100000 && x-1>=100000 && 2*x<=100000)
        {mint = dfs(x-1,t+1);}
    if(!visit[x+1] && x+1<=100000 && x-1>=100000 && 2*x<=100000)
        {dfs(x+1,t+1);}
    if(!visit[x*2] && x+1<=100000 && x-1>=100000 && 2*x<=100000)
        {dfs(x*2,t+1);}
}
int main()
{

    cin >> N >> K;


    cout << dfs(N,0);
}
