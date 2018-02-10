//https://www.acmicpc.net/problem/3055
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
char map[52][52];
int visited[52][52];
int R, C;
int sy1, sx1, desy, desx;
bool wchk;
int cnt;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};
queue< pair<int, int> > water;

void input(){
     cin >> R >> C;
     for(int i=0; i<R; i++)
          cin >> map[i];

}

void find_start_point(){
     for(int i=0; i<R; i++){
          for(int j=0; j<C; j++){
               if(map[i][j]=='*'){
                    water.push(make_pair(i,j));
                    wchk=1;
                    cnt++;
               }
               if(map[i][j]=='S'){
                    sy1=i;
                    sx1=j;
               }
               if(map[i][j]=='D'){
                    desy=i;
                    desx=j;
               }
          }
     }
}

void bfs(){
     queue< pair<int, int> > q;
     q.push(make_pair(sy1,sx1));
     int cnt2=0;
     int tmp=cnt;
     int tmp2=1;
     int y,x;
     visited[sy1][sx1]=1;
cnt=0;
     while(!q.empty()){
          while(tmp-->0 && wchk){
               int wy=water.front().first;
               int wx=water.front().second;
               water.pop();

               for(int i=0; i<4; i++){
                    int nwy=wy+dy[i];
                    int nwx=wx+dx[i];

                    if(nwy>=0 && nwy<R && nwx>=0 && nwx<C){
                         if(map[nwy][nwx]!='X' && (map[nwy][nwx]=='.' || map[nwy][nwx]=='S')){
                              cnt++;
                              water.push(make_pair(nwy,nwx));
                              map[nwy][nwx]='*';
                         }
                    }
               }
          }
          
          tmp=cnt;
          cnt=0;
          cnt2=0;
          while(tmp2-->0){
               y=q.front().first;
               x=q.front().second;
               q.pop();
               for(int i=0; i<4; i++){
                    int ny=y+dy[i];
                    int nx=x+dx[i];

                    if(ny>=0 && ny<R && nx>=0 && nx<C){
                         if(map[ny][nx]!='*' && map[ny][nx]!='X' && !visited[ny][nx]){
                              q.push(make_pair(ny,nx));
                              cnt2++;
                              visited[ny][nx]=visited[y][x]+1;
                         }
                    }
               }
          }
          tmp2=cnt2;
     }
}

int main(){
     input();
     find_start_point();
     bfs();

     if(!visited[desy][desx]) cout << "KAKTUS";
     else cout << visited[desy][desx]-1;
}
