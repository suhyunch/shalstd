#include <iostream>
#include <queue>//bfs
using namespace std;
int box[1002][1002];
int ripen[1002][1002];

struct xy
{
    int x;
    int y;
};
int main()
{
    queue<xy> q;
    int M, N;
    cin >> M >> N;
    int cnt=0;
    int result=0;

    for(int i=0; i<=M+1; i++)
    {
       box[0][i]=1;
       box[N+1][i]=1;
     }
     for(int i=1; i<=N; i++)
     {
       box[i][0]=1;
       box[i][M+1]=1;
     }
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {
            xy tomato;
            cin >> box[i][j];
            ripen[i][j]=box[i][j];
            if(box[i][j]==1)
            {
                cnt++;
                tomato.x=j;
                tomato.y=i;
                q.push(tomato);
            }
        }
    }
    bool chk1;
    while(!q.empty())
    {
      int cnt_while=0;
      for(int i=0; i<cnt; i++)
      {
        chk1=1;
        xy now=q.front();
        q.pop();
        xy adj;
        if(box[now.y-1][now.x]==0 && ripen[now.y-1][now.x]==0)
        {
          adj.y=now.y-1;
          adj.x=now.x;
          q.push(adj);
          ripen[adj.y][adj.x]=1;
          cnt_while++;
          chk1=0;
        }
        if(box[now.y][now.x+1]==0 && ripen[now.y][now.x+1]==0)
        {
          adj.y=now.y;
          adj.x=now.x+1;
          q.push(adj);
          ripen[adj.y][adj.x]=1;
          cnt_while++;
          chk1=0;
        }
        if(box[now.y+1][now.x]==0 && ripen[now.y+1][now.x]==0)
        {
          adj.y=now.y+1;
          adj.x=now.x;
          q.push(adj);
          ripen[adj.y][adj.x]=1;
          cnt_while++;
          chk1=0;
        }
        if(box[now.y][now.x-1]==0 && ripen[now.y][now.x-1]==0)
        {
          adj.y=now.y;
          adj.x=now.x-1;
          q.push(adj);
          ripen[adj.y][adj.x]=1;
          cnt_while++;
          chk1=0;
        }
      }
      cnt=cnt_while;
      result++;
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
          if(ripen[i][j]==0)
          {
             cout << "-1";
             return 0;
           }
         }
    if(chk1 && result==2) cout << "-1";
    else cout << result-1;
    system("pause");
}
