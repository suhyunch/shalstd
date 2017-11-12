#include <iostream>
#include <string.h>
using namespace std;
bool map[11][11];
bool visited [11];
int maxcnt;
 int N, M;

void dfs(int root, int x)
{
    visited[root]=1;
    if(maxcnt<x) maxcnt=x;
    for(int i=1; i<=N; i++)
    {
        if(root != i && map[root][i] && !visited[i])
            {dfs(i, x+1); visited[i]=0; }
    }
}
int main()
{
    int T;
    cin >> T;
    for(int i=1; i<=T; i++)
    {
        //init
        memset(map,0,sizeof(map));
        memset(visited,false,sizeof(visited));


        cin >> N >> M;

        if(M == 0)
        {
            cout<<"#"<<i<<" "<<1<<'\n';
            continue;
        }

        for(int j=0; j<M; j++)
        {
            int x,y;
            cin >> x >> y;
            map[x][y]=1;
            map[y][x]=1;
        }

        maxcnt=0;
        for(int j=1; j<=N; j++)
        {
            memset(visited,false,sizeof(visited));
            dfs(j,1);

        }
        cout <<"#" << i << " " ;
        cout << maxcnt << endl;
    }
}
