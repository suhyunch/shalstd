//https://www.acmicpc.net/problem/13460
#include <iostream>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class ball{
public:
     int x;
     int y;
     bool input;
};
char map[10][10];
char tmp[11][10][10];
int N, M;
void solve(int dir, int cnt);
bool move(bool color, int dir);
ball red;
ball blue;
int mn=11;
bool chk=0;
int main(){
     cin >> N >> M;
     red.input=0;
     blue.input=0;

     for(int i=0; i<N; i++){
          cin >> map[i];
          if(red.input && blue.input) continue;
          for(int j=0; j<M; j++){
               if(map[i][j]=='R'){
                    red.y=i;
                    red.x=j;
                    red.input=true;
               }
               if(map[i][j]=='B'){
                    blue.y=i;
                    blue.x=j;
                    blue.input=true;
               }
          }
     }


     //for(int i=0; i<4; i++)
          solve(0, 1);


     if(mn==11) cout <<"-1";
     else cout << mn;
}

void solve(int dir, int cnt){

     if(cnt==11) {
          return;
     }

          for(int i=0; i <N; i++){
               for(int j=0; j<M; j++)
                    tmp[cnt][i][j]=map[i][j];
          }
          cout << dir <<" ??? " <<cnt <<endl;
          cout << "RED :: " << red.y << " " << red.x <<endl;
          cout << "BLUE :: " << blue.y << " " << blue.x << endl;
//dir 방향으로 구슬 이동_simulation
     if(dir==UP){
          if(red.y<blue.y){
               if(move(0, dir) && !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
               if(move(1, dir)){
                    chk=1;
                    return;
               }
          }
          else {
               if(move(1, dir)){
                    chk=1;
                    return;
               }
               if(move(0, dir) && !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
          }
     }
     else if(dir==DOWN){
          if(red.y>blue.y){
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
               if(move(1, dir)){
                    chk=1;
                    return;
               }
          }
          else {
               if(move(1, dir)){
                    chk=1;
                    return;
               }
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
          }
     }
     else if(dir==LEFT){
          if(red.x<blue.x){
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
               if(move(1, dir)){
                    chk=1;
                    return;
               }
          }
          else {
               if(move(1, dir)){
                    chk=1;
                    return;
               }
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
          }
     }
     else{ // dir==RIGHT
          if(red.y>blue.y){
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
               if(move(1, dir)){
                    chk=1;
                    return;
               }
          }
          else {
               if(move(1, dir)){
                    chk=1;
                    return;
               }
               if(move(0, dir)&& !chk){
                    if(mn>cnt) mn=cnt;
                    return;
               }
          }
     }
     cout << dir << " -------- " << cnt  <<endl;
     for(int i=0; i <N; i++){
          cout << map[i] <<"   " << tmp[cnt][i]<< endl;
     }cout << endl;

//dfs로 다음 이동 방향 설정
     for(int i=0; i<4; i++){
          if(i==dir) continue;
          solve(i, cnt+1);
          for(int j=0; j<N; j++)
               for(int k=0; k<M; k++){
                    map[i][j]=tmp[cnt][i][j];
                    if(tmp[cnt][i][j]=='R'){
                         red.y=i;
                         red.x=j;
                    }
                    if(tmp[cnt][i][j]=='B'){
                         blue.y=i;
                         blue.x=j;
                    }
               }
     }

     cout << dir << " -------- " << cnt  <<endl;
     for(int i=0; i <N; i++){
          cout << map[i] <<"   " << tmp[cnt][i]<< endl;
     }cout << endl;
}

bool move(bool color, int dir){
     //color 0 red, 1 blue, 이동 방향
     switch(dir){
          case UP :
               if(!color){
                    for(int i=red.y; i>0; i--){
                         if(map[i-1][red.x] == 'O') return true;
                         if(map[i-1][red.x] != '.') { //이동불가
                              map[red.y][red.x] = '.';
                              map[i][red.x] = 'R';
                              red.y=i;
                              break;
                         }
                    }
               }
               else{
                    for(int i=blue.y; i>0; i--){
                         if(map[i-1][blue.x] == 'O') return true;
                         if(map[i-1][blue.x] != '.') {
                              map[blue.y][blue.x] = '.';
                              map[i][blue.x] = 'B';
                              blue.y=i;
                              break;
                         }
                    }
               }
               break;
          case DOWN :
               if(!color){
                    for(int i=red.y; i<N; i++){
                         if(map[i+1][red.x] == 'O') return true;
                         if(map[i+1][red.x] != '.') {
                              map[red.y][red.x] = '.';
                              map[i][red.x] = 'R';
                              red.y=i;
                              break;
                         }
                    }
               }
               else{
                    for(int i=blue.y; i<N; i++){
                         if(map[i+1][blue.x] == 'O') return true;
                         if(map[i+1][blue.x] != '.') {
                              map[blue.y][blue.x] = '.';
                              map[i][blue.x] = 'B';
                              blue.y=i;
                              break;
                         }
                    }
               }
               break;
          case LEFT :
               if(!color){
                    for(int i=red.x; i>0; i--){
                         if(map[red.y][i-1] == 'O') return true;
                         if(map[red.y][i-1] != '.') {
                              map[red.y][red.x] = '.';
                              map[red.y][i] = 'R';
                              red.x=i;
                              break;
                         }
                    }
               }
               else{
                    for(int i=blue.x; i>0; i--){
                         if(map[blue.y][i-1] == 'O') return true;
                         if(map[blue.y][i-1] != '.') {
                              map[blue.y][blue.x] = '.';
                              map[blue.y][i] = 'B';
                              blue.x=i;
                              break;
                         }
                    }
               }
               break;
          case RIGHT :
               if(!color){
                    for(int i=red.x; i<N; i++){
                         if(map[red.y][i+1] == 'O') return true;
                         if(map[red.y][i+1] != '.') {
                              map[red.y][red.x] = '.';
                              map[red.y][i] = 'R';
                              red.x=i;
                              break;
                         }
                    }
               }
               else{
                    for(int i=blue.x; i<N; i++){
                         if(map[blue.y][i+1] == 'O') return true;
                         if(map[blue.y][i+1] != '.') {
                              map[blue.y][blue.x] = '.';
                              map[blue.y][i] = 'B';
                              blue.x=i;
                              break;
                         }
                    }
               }
               break;
     }
     return false;
}
