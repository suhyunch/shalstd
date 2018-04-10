#include <cstdio>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, k, cnt, sum, ret = 0, maxLen = 0, maxV = 0, minV = 1000000000;
int maap[101][101];
bool visit[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool chk[101][101];

struct node
{
    int cnt, maxcnt, dir;
};

node map[101][101];
node nMap[101][101];

void solve()
{
    for(int a=0;a<m;a++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(map[i][j].cnt > 0)
                {
                    int dir = map[i][j].dir;
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];

                    if(nx == 0 || ny == 0 || nx == n-1 || ny == n-1)
                    {
                        nMap[nx][ny].cnt = map[i][j].cnt / 2;
                        nMap[nx][ny].maxcnt = nMap[nx][ny].cnt;

                        if(dir == 0 || dir == 2)
                            dir += 1;
                        else
                            dir -= 1;

                        nMap[nx][ny].dir = dir;

                    }

                    else{

                        if(nMap[nx][ny].maxcnt > 0)
                        {
                            nMap[nx][ny].cnt += map[i][j].cnt;

                            if(map[i][j].cnt > nMap[nx][ny].maxcnt)
                            {
                                nMap[nx][ny].maxcnt = map[i][j].cnt;
                                nMap[nx][ny].dir = map[i][j].dir;

                            }
                        }

                        else
                        {
                            nMap[nx][ny].cnt = map[i][j].cnt;
                            nMap[nx][ny].maxcnt = nMap[nx][ny].cnt;
                            nMap[nx][ny].dir = map[i][j].dir;
                        }
                    }


                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                map[i][j] = nMap[i][j];
                nMap[i][j] = {0, 0, 0};
            }
        }

                  cout << endl;
           for(int i=0; i<n ;i++){
                    for(int j=0; j<n; j++){
                            printf("(%d, %d, %d, %d, %d) ", i, j, map[i][j].cnt,map[i][j].maxcnt,map[i][j].dir );
                      }cout << endl;
                  }
                  cout << endl;
             }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j].cnt != 0)
                ret += map[i][j].cnt;
        }
    }
}

int main()
{
    int t;
    cin>>t;

    for(int a=1;a<=t;a++)
    {
        memset(map, 0, sizeof(map));
        memset(nMap, 0, sizeof(nMap));
        ret = 0;

        cin>>n>>m>>k;

        for(int i=0;i<k;i++)
        {
            int x, y, cnt, dir;
            cin>>x>>y>>cnt>>dir;

            map[x][y] = {cnt, cnt, dir-1};
        }


        solve();

        printf("#%d %d\n", a, ret);
    }

    return 0;
}
