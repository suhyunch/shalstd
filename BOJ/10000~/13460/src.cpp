//https://www.acmicpc.net/problem/13460
#include <iostream>
#include <algorithm>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

class ball{
public :
     int x;
     int y;
     ball(int _x=0, int _y=0) : x(_x), y(_y) {}
};
char map[10][10];
char cache[11][10][10];
int N, M;
int mn=11;

ball R;
ball B;
int chk;
//bool chk_10=1;
//map input
void input(){
     cin >> N >> M;
     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               cin >> map[i][j];
               if(map[i][j]=='R'){
                    R.y=i;
                    R.x=j;
               }
               else if(map[i][j]=='B'){
                    B.y=i;
                    B.x=j;
               }
          }
     }
     return;
}
//idx번째 cache에 현재 map 저장
void store_map(int idx){
     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               cache[idx][i][j]=map[i][j];
          }
     }
     return;
}
//idx번째 cache를 현재 map으로 불러오기
void load_map(int idx){
     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               map[i][j]=cache[idx][i][j];
               if(map[i][j]=='R'){
                    R.y=i;
                    R.x=j;
               }
               if(map[i][j]=='B'){
                    B.y=i;
                    B.x=j;
               }
          }
     }
     return;
}
//이동 시뮬레이션
void move(bool color, int dir){
     if(dir==UP){
          if(color){
               for(int i=R.y; i>=0; i--){
                    if(map[i][R.x]=='O'){
                         map[R.y][R.x]='.';
                         chk=1;
                         return;
                    }
                    else if(map[i][R.x]=='#'||map[i][R.x]=='B'){
                         return;
                    }
                    else if(map[i][R.x]=='.'){
                         map[i][R.x]='R';
                         map[R.y][R.x]='.';
                         R.y=i;
                    }
               }
          }
          else{
               for(int i=B.y; i>=0; i--){
                    if(map[i][B.x]=='O'){
                         if(chk==0) chk=2;
                         else if(chk==1) chk=3;
                         return;
                    }
                    else if(map[i][B.x]=='#'||map[i][B.x]=='R'){
                         return;
                    }
                    else if(map[i][B.x]=='.'){
                         map[i][B.x]='B';
                         map[B.y][B.x]='.';
                         B.y=i;
                    }
               }
          }
     }//if(dir==UP)
     if(dir==DOWN){
          if(color){
               for(int i=R.y; i<N; i++){
                    if(map[i][R.x]=='O'){
                         map[R.y][R.x]='.';
                         chk=1;
                         return;
                    }
                    else if(map[i][R.x]=='#'||map[i][R.x]=='B'){
                         return;
                    }
                    else if(map[i][R.x]=='.'){
                         map[i][R.x]='R';
                         map[R.y][R.x]='.';
                         R.y=i;
                    }
               }
          }
          else{
               for(int i=B.y; i<N; i++){
                    if(map[i][B.x]=='O'){
                         if(chk==0) chk=2;
                         else if(chk==1) chk=3;
                         return;
                    }
                    else if(map[i][B.x]=='#'||map[i][B.x]=='R'){
                         return;
                    }
                    else if(map[i][B.x]=='.'){
                         map[i][B.x]='B';
                         map[B.y][B.x]='.';
                         B.y=i;
                    }
               }
          }
     }//(dir==DOWN)
     if(dir==LEFT){
          if(color){
               for(int i=R.x; i>=0; i--){
                    if(map[R.y][i]=='O'){
                         map[R.y][R.x]='.';
                         chk=1;
                         return;
                    }
                    else if(map[R.y][i]=='#'||map[R.y][i]=='B'){
                         return;
                    }
                    else if(map[R.y][i]=='.'){
                         map[R.y][i]='R';
                         map[R.y][R.x]='.';
                         R.x=i;
                    }
               }
          }
          else{
               for(int i=B.x; i>=0; i--){
                    if(map[B.y][i]=='O'){
                         if(chk==0) chk=2;
                         else if(chk==1) chk=3;
                         return;
                    }
                    else if(map[B.y][i]=='#'||map[B.y][i]=='R'){
                         return;
                    }
                    else if(map[B.y][i]=='.'){
                         map[B.y][i]='B';
                         map[B.y][B.x]='.';
                         B.x=i;
                    }
               }
          }
     }//if(dir==LEFT)
     if(dir==RIGHT){
          if(color){
               for(int i=R.x; i<M; i++){
                    if(map[R.y][i]=='O'){
                         map[R.y][R.x]='.';
                         chk=1;
                         return;
                    }
                    else if(map[R.y][i]=='#'||map[R.y][i]=='B'){
                         return;
                    }
                    else if(map[R.y][i]=='.'){
                         map[R.y][i]='R';
                         map[R.y][R.x]='.';
                         R.x=i;
                    }
               }
          }
          else{
               for(int i=B.x; i<M; i++){
                    if(map[B.y][i]=='O'){
                         if(chk==0) chk=2;
                         else if(chk==1) chk=3;
                         return;
                    }
                    else if(map[B.y][i]=='#'||map[B.y][i]=='R'){
                         return;
                    }
                    else if(map[B.y][i]=='.'){
                         map[B.y][i]='B';
                         map[B.y][B.x]='.';
                         B.x=i;
                    }
               }
          }
     }
     return;
}

void dfs(int dir, int depth){
     if(dir==UP){
          if(R.y<B.y){
               move(1, dir);
               move(0, dir);
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==DOWN){
          if(R.y>B.y){
               move(1, dir);
               move(0, dir);
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==LEFT){
          if(R.x<B.x){
               move(1, dir);
               move(0, dir);
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }
     else if(dir==RIGHT){
          if(R.x>B.x){
               move(1, dir);
               move(0, dir);
          }
          else{
               move(0, dir);
               move(1, dir);
          }
     }


     if(chk==2 || chk==3){
          chk=0;
          return;
     }
     else if(chk==1){
          //mn 비교
          mn=min(mn, depth);
          chk=0;
          return;
     }
     store_map(depth);
     for(int i=0; i<4; i++){
          if(depth<mn && depth<10){
               dfs(i, depth+1);
               load_map(depth);
          }
     }
     return;
}

void process(){
     store_map(0);
     for(int i=0; i<4; i++){
          dfs(i, 1);
          load_map(0);
     }
     return;
}

int main(){
     input();
     process();

     if(mn==11) cout <<"-1";
     else cout << mn;
}
