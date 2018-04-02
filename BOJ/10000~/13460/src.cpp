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
char cache[11][10][10];
int N, M;
void solve(int dir, int cnt);
void move(bool color, int dir);
ball R;
ball B;
int mn=11;
int chk_0=0;
int main(){
     cin >> N >> M;
     R.input=0;
     B.input=0;

     for(int i=0; i<N; i++){
          cin >> map[i];
          if(R.input && B.input) continue;
          for(int j=0; j<M; j++){
               if(map[i][j]=='R'){
                    R.y=i;
                    R.x=j;
                    R.input=true;
               }
               if(map[i][j]=='B'){
                    B.y=i;
                    B.x=j;
                    B.input=true;
               }
          }
     }


     //for(int i=0; i<4; i++){
     //     chk_0=0;
          solve(3, 1);
     //     cout << mn <<endl;
     //}

     if(mn==11) cout <<"-1";
     else cout << mn;
}

void solve(int dir, int cnt){//dir: 현재 기울이고 있는 방향 , cnt: 현재까지 기울인 횟수
     cout << endl << dir << "-------" << cnt <<"/" <<mn << endl;
     for(int j=0; j<N; j++)
          cout << map[j] << endl;
     if(cnt==11){
          return;
     }
     cout << "RED :: " << R.y << " " << R.x <<endl;
          cout << "BLUE :: " << B.y << " " << B.x << endl;
//현재 상태 캐시에 저장
     for(int i=0; i<N; i++)
          for(int j=0; j<M; j++)
               cache[cnt][i][j]=map[i][j];
//주의 할 것, R B가 구멍에 들어간 상태에서는 저장할 필요 x 시뮬레이션 진행하면서 공이 구멍에 들어갈 경우 return 해서 시뮬레이션 끝내기
     chk_0=0;
     cout << chk_0 << "!!" << endl;
     if(dir==UP){
          if(R.y < B.y){
               move(1, dir);
               move(0, dir);
               //빨강공 이동 후 파랑공 이동
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==DOWN){
          if(R.y > B.y){
               move(1, dir);
               move(0, dir);
               //빨강공 이동 후 파랑공 이동
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==LEFT){
          if(R.x < B.x){
               move(1, dir);
               move(0, dir);
               //빨강공 이동 후 파랑공 이동
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==RIGHT){
          if(R.x > B.x){
               move(1, dir);
               move(0, dir);
               //빨강공 이동 후 파랑공 이동
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     cout << chk_0 << "?" <<endl;
     if(chk_0 !=0){
          for(int j=0; j<N; j++){
               cout << map[j] << endl;
               for(int k=0; k<M; k++)
                    map[j][k]=cache[cnt][j][k];
          }

          if(chk_0==1 && mn>cnt) mn=cnt;
          cout << cnt << "-------------------------------" << mn <<endl;
          chk_0=0;
          return;
     }
     for(int j=0; j<N; j++)
          cout << map[j] << endl;
//dfs로 다음 이동 정하기
     for(int i=0; i<4; i++){
          if(i==dir) continue;
          solve(i, cnt+1);
          //캐시에 있는 현재 이동 상태의 map 호출
          cout << "out++++++++++++++++++++++++++++++++++++++++++++"<<cnt<<endl;
          for(int j=0; j<N; j++){
               cout << map[j]<< "   " << cache[cnt][j]<<endl;
               for(int k=0; k<M; k++){

                    map[j][k]=cache[cnt][j][k];
                    if(map[j][k]=='R') {
                         R.y=j;
                         R.x=k;
                    }
                    if(map[j][k]=='B'){
                         B.y=j;
                         B.x=k;
                    }
               }

          }
          chk_0=0;
     }
     return;
}

void move(bool color, int dir){
     //color 1 :: red, 0 :: blue,
     if(dir==UP){
          if(color){//현재 이동하는 공 색이 red
               for(int i=R.y; i>0; i--){
                    if(map[i-1][R.x] == 'O') {
                         if(chk_0==0) chk_0=1;
                         return;
                    }
                    if(map[i-1][R.x] != '.') { //이동불가_ #, B 일 때
                         map[R.y][R.x] = '.';
                         map[i][R.x] = 'R';
                         R.y=i;
                         return;
                    }
               }
          }
          else{
               for(int i=B.y; i>0; i--){
                    if(map[i-1][B.x] == 'O') {
                         if(chk_0==0) chk_0=2;
                         return;
                    }
                    if(map[i-1][B.x] != '.') {
                         map[B.y][B.x] = '.';
                         map[i][B.x] = 'B';
                         B.y=i;
                         return;
                    }
               }
          }
     }
     if(dir==DOWN){
          if(color){//현재 이동하는 공 색이 red
               for(int i=R.y; i<N; i++){
                    if(map[i+1][R.x] == 'O')  {
                         if(chk_0==0) chk_0=1;
                         return;
                    }
                    if(map[i+1][R.x] != '.') { //이동불가_ #, B 일 때
                         map[R.y][R.x] = '.';
                         map[i][R.x] = 'R';
                         R.y=i;
                         return;
                    }
               }
          }
          else{
               for(int i=B.y; i<N; i++){
                    if(map[i+1][B.x] == 'O') {
                         if(chk_0==0) chk_0=2;
                         return;
                    }
                    if(map[i+1][B.x] != '.') {
                         map[B.y][B.x] = '.';
                         map[i][B.x] = 'B';
                         B.y=i;
                         return;
                    }
               }
          }
     }
     if(dir==LEFT){
          if(color){//현재 이동하는 공 색이 red
               for(int i=R.x; i>0; i--){
                    if(map[R.y][i-1] == 'O')  {
                         if(chk_0==0) chk_0=1;
                         return;
                    }
                    if(map[R.y][i-1] != '.') { //이동불가_ #, B 일 때
                         map[R.y][R.x] = '.';
                         map[R.y][i] = 'R';
                         R.x=i;
                         return;
                    }
               }
          }
          else{
               for(int i=B.x; i>0; i--){
                    if(map[B.y][i-1] == 'O') {
                         cout << "here" << endl;
                         if(chk_0==0) chk_0=2;
                         return;
                    }
                    if(map[B.y][i-1] != '.') { //이동불가_ #, B 일 때
                         map[B.y][B.x] = '.';
                         map[B.y][i] = 'B';
                         B.x=i;
                         return;
                    }
               }
          }
     }
     if(dir==RIGHT){
          if(color){//현재 이동하는 공 색이 red
               for(int i=R.x; i<N; i++){
                    cout << R.y << " " << i+1 << " " <<map[R.y][i+1] <<" ~~  "<< chk_0  <<endl;
                    if(map[R.y][i+1] == 'O')  {
                         if(chk_0==0) chk_0=1;
                         cout << "now -----------" << chk_0 << endl;
                         return;
                    }
                    if(map[R.y][i+1] != '.') { //이동불가_ #, B 일 때
                         map[R.y][R.x] = '.';
                         map[R.y][i] = 'R';
                         R.x=i;
                         return;
                    }
               }
          }
          else{
               for(int i=B.x; i<N; i++){
                    if(map[B.y][i+1] == 'O') {
                         if(chk_0==0) chk_0=2;
                         return;
                    }
                    if(map[B.y][i+1] != '.') { //이동불가_ #, B 일 때
                         map[B.y][B.x] = '.';
                         map[B.y][i] = 'B';
                         B.x=i;
                         return;
                    }
               }
          }
     }
     return;
}
