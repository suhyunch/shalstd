#include <iostream>
#include <cstring>
using namespace std;

class micro{
public:
     int dir;
     int mx;
     int num;
     void reset(){
          this->dir=0;
          this->mx=0;
          this->num=0;
     }
};
int N, M, K;
micro map[100][100];
micro map_tmp[100][100];
int dy[5]={0, -1, 1, 0, 0 };
int dx[5]={0, 0, 0, -1, 1 };
//(상: 1, 하: 2, 좌: 3, 우: 4)

void init(){
     for(int i=0; i<100; i++){
          for(int j=0; j<100; j++){
               map[i][j].reset();
               map_tmp[i][j].reset();
          }
     }
}


void input(){
     cin >> N >> M >> K;

     while(K-->0){
          int y, x, nmicro, dir;

          cin >> y >> x >> nmicro >> dir;
          map[y][x].dir=dir;
          map[y][x].mx=map[y][x].num=nmicro;
     }
}
void copy(){
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               map[i][j]=map_tmp[i][j];
               map_tmp[i][j].reset();
          }
     }
}
void solve(){
     while(M-->0){
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    if(map[i][j].num!=0){
                         int ny=i+dy[map[i][j].dir];
                         int nx=j+dx[map[i][j].dir];

                         if(ny==0 || ny==N-1 || nx==0 ||nx==N-1){//이동할 곳이 가장자리
                              if(map[i][j].dir==1) map_tmp[ny][nx].dir=2;
                              if(map[i][j].dir==2) map_tmp[ny][nx].dir=1;
                              if(map[i][j].dir==3) map_tmp[ny][nx].dir=4;
                              if(map[i][j].dir==4) map_tmp[ny][nx].dir=3;

                              map_tmp[ny][nx].num=map_tmp[ny][nx].mx=map[i][j].num/2;
                         }
                         else{// 이동할 곳이 가장자리가 아니라면
                              if(map_tmp[ny][nx].mx==0){
                                   map_tmp[ny][nx].dir=map[i][j].dir;
                                   map_tmp[ny][nx].mx=map[i][j].num;
                                   map_tmp[ny][nx].num=map[i][j].num;
                              }
                              else{
                                   map_tmp[ny][nx].num+=map[i][j].num;
                                   if(map_tmp[ny][nx].mx< map[i][j].num){
                                        map_tmp[ny][nx].mx=map[i][j].num;
                                        map_tmp[ny][nx].dir=map[i][j].dir;
                                   }

                              }
                         }
                    }

               }
          }

          copy();
     }
}
int howmany(){
     int res=0;
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               res+=map[i][j].num;
          }
     }
     return res;
}
int main(){
     int tc;
     cin >> tc;

     for(int T=1; T<=tc; T++){
          init();
          input();
          solve();
          int ans=howmany();
          cout << "#" << T << " " << ans << endl;
     }
}
