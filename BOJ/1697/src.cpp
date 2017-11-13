#include <iostream>
#include <queue>
using namespace std;
int N, K, t;
bool visit[100000];

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while(!q.empty())
    {
        x = q.front();
        visit[x]=1;
        cout << x << endl;
        q.pop();
        t++;
        if(x==K) break;
        if(visit[x]) continue;
        if(x-1>=0 && x+1<=100000 && x*2 <=100000)
        {
            if(!visit[x-1]) q.push(x-1);
            if(!visit[x+1]) q.push(x+1);
            if(!visit[2*x]) q.push(x*2);
        }
        else if(x==0) if(!visit[x+1]) q.push(x+1);
        else if(x*2>100000 && x+1<=100000)
        {
            if(!visit[x-1]) q.push(x-1);
            if(!visit[x+1]) q.push(x+1);
        }
        else if(x==100000) if(!visit[x-1]) q.push(x-1);

    }

}
int main()
{

    cin >> N >> K;

    bfs(N);
    cout << t;
}
