//https://www.acmicpc.net/problem/3190
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, K, L;

int map[100][100];

//머리의 방향
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
//머리의 방향에 따른 다음 이동 방향
//UP일 때, ny=y+dy[0], nx=x+dx[0]...
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

//뱀 몸통은 큐를 이용
//사과를 먹지않으면 꼬리(=front, 제일 처음 집어넣은 값) pop
//매초 이동시에 머리(=back, 제일 마지막에 집어넣은 값) push
queue<pair <int, int> > snake;

int main(){
     cin >> N >> K;
     map[0][0]=1;//뱀 초기 위치
     snake.push(make_pair(0,0));
     bool chk=0;

     for(int i=0; i<K; i++){
          int y, x;
          cin >> y >> x;
          map[y-1][x-1]=2;//사과가 존재함
         //주어진 문제는 (1,1)~(N,N) 의 맵
         //0,0에서 시작하고 사과의 위치를 -1,-1씩 옮겨줌
     }

     cin >> L;
     int t;
     int D=RIGHT;//뱀의 머리 방향, 최초에 오른쪽
     char dir;

     int tmp=0;//시간 진행 체크
     for(int i=0; i<L; i++){
          cin >> t >> dir;
          for(; tmp<t; tmp++){ //현재 시간<다음 머리 방향 바꾸는 시간
               int ny=snake.back().first+dy[D];
               int nx=snake.back().second+dx[D];
               if(ny<0 || ny>=N ||nx <0 || nx>=N || map[ny][nx]==1) {
                    chk=1;
                    tmp++;
                    break;
                   //벽이나 몸통에 부딪히면 break;
               }
               if(map[ny][nx]==2){
                    snake.push(make_pair(ny, nx));
                    map[ny][nx]=1;
                   //사과를 먹은 경우, 머리만 이동해줌, 머리 부분은 1로 바꾸기
               }
               else if(map[ny][nx]==0){
                    snake.push(make_pair(ny, nx));
                    map[ny][nx]=1;
                    map[snake.front().first][snake.front().second]=0;
                    snake.pop();
                   //빈 공간일 경우, 머리를 이동해주고, 꼬리를 땡김
                   //pop이 꼬리부분 땡기는 것(큐 젤 앞에 있는 것 삭제)
                   //꼬리를 땡긴 부분은 0으로 map을 바꿔줌
               }
          }
          if(chk==0) tmp=t;
         //t-1초까지 뱀의 이동을 해주었다면, t 초에 머리 방향을 바꿔줌
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
              //벽 또는 몸통에 부딪히면
               chk=1;
               tmp++;
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


     cout << tmp;
     return 0;
}
