//https://www.acmicpc.net/problem/7562
#include <iostream>
#include <queue>
using namespace std;
int map[300][300];
int sy,sx,dy,dx, I;

int diry[8]={2,2,1,1,-1,-1,-2,-2};
int dirx[8]={-1,1,-2,2,-2,2,-1,1};

void bfs(int starty, int startx)
{
     queue<int> q;
     q.push(starty*1000+startx);
     map[starty][startx]=1;
     bool chk=1;
     while(chk && !q.empty()){
          int nowy=q.front()/1000;
          int nowx=q.front()%1000;
          q.pop();


          for(int i=0; i<8; i++)
          {
               int nexty=nowy+diry[i];
               int nextx=nowx+dirx[i];

               if(nexty >=0 && nexty <I && nextx>=0 && nextx<I && !map[nexty][nextx])
               {
                    q.push(nexty*1000+nextx);
                    map[nexty][nextx]=map[nowy][nowx]+1;
                    if(nexty==dy && nextx==dx) { chk=0; break;}
               }
          }

     }

}


int main()
{
     int t;
     cin >> t;

     for(int i=0; i<t; i++)
     {
          cin >> I;
          for(int j=0; j<I; j++)
               for(int k=0; k<I; k++)
                    map[j][k]=0;

          cin >> sy >> sx >> dy >> dx;

          bfs(sy,sx);
          if(map[dy][dx]==0) cout << "0" <<endl;
          else cout << map[dy][dx]-1 << endl;
     }
}
