//https://www.acmicpc.net/problem/3190
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, K, L;

int map[100][100];

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

queue<pair <int, int> > snake;

int main(){
     cin >> N >> K;
     map[0][0]=1;//뱀 초기 위치
     snake.push(make_pair(0,0));
     int t_idx=0;//tail index
     bool chk=0;

     for(int i=0; i<K; i++){
          int y, x;
          cin >> y >> x;
          map[y-1][x-1]=2;//사과가 존재함
     }

     cin >> L;
     int t;
     int D=RIGHT;//뱀의 머리 방향
     char dir;

     int tmp=0;
     for(int i=0; i<L; i++){
          cin >> t >> dir;
          for(; tmp<t; tmp++){
               int ny=snake.back().first+dy[D];
               int nx=snake.back().second+dx[D];
               if(ny<0 || ny>=N ||nx <0 || nx>=N || map[ny][nx]==1) {
                    chk=1;
                    break;
               }
               if(map[ny][nx]==2){
                    snake.push(make_pair(ny, nx));
                    map[ny][nx]=1;
               }
               else if(map[ny][nx]==0){
                    snake.push(make_pair(ny, nx));
                    map[ny][nx]=1;
                    map[snake.front().first][snake.front().second]=0;
                    snake.pop();
               }
          }
          if(chk==0) tmp=t;
          if(dir=='D'){
               D=(D+1)%4;
          }
          else if(dir=='L'){
               D=(D+3)%4;
          }
          if(chk) break;
     }

     while(!chk){
          int ny=snake.back().first+dy[D];
          int nx=snake.back().second+dx[D];
          if(ny<0 || ny>=N ||nx <0 || nx>=N || map[ny][nx]==1) {
               chk=1;
               break;
          }
          if(map[ny][nx]==2){
               snake.push(make_pair(ny, nx));
               map[ny][nx]=1;
          }
          else if(map[ny][nx]==0){
               snake.push(make_pair(ny, nx));
               map[ny][nx]=1;
               map[snake.front().first][snake.front().second]=0;
               snake.pop();
          }

          tmp++;
     }


     cout << tmp+1;

}
