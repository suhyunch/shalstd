//https://www.acmicpc.net/problem/4963
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

bool map[50][50];
bool visited[50][50];
int cnt;
int w, h;
int dy[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dx[8]={-1, 0, 1, -1, 1, -1, 0, 1};
void bfs(int y, int x){
     queue<pair<int, int> > q;

     q.push(make_pair(y,x));
     map[y][x]=0;
     int nowy;
     int nowx;
     while(!q.empty()){
           nowy=q.front().first;
           nowx=q.front().second;
           q.pop();

           for(int i=0; i<8; i++){
                int ny=nowy+dy[i];
                int nx=nowx+dx[i];
                if(ny<h && ny>=0 && nx<w && nx>=0){
                     if(map[ny][nx]==1){
                          map[ny][nx]=0;
                          q.push(make_pair(ny,nx));
                     }
                }
           }
     }
     cnt++;
     return;
}
int main(){
     while(true){
          cnt=0;
          cin >> w >> h;
          if(w==0 && h==0) break;
          for(int i=0; i<h; i++){
               for(int j=0; j<w; j++){
                    cin >> map[i][j];
               }
          }

          for(int i=0; i<h; i++){
               for(int j=0; j<w; j++){
                    if(map[i][j]==1){
                         bfs(i, j);
                    }
               }
          }
          cout << cnt <<endl;
     }
     return 0;
}
