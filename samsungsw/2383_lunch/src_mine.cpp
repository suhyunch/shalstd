#include <iostream>
#include <math.h>
using namespace std;

#define MAXN 11
#define MAXT 144

struct pos{
     int y, x;
     pos() {}
     pos(int y, int x) : y(y), x(x) {}
};

int N, M, S;
int map[11][11];
int match[11];
int ans;

pos man[11];
pos stair[2];

int dist(int man_idx, int stair_idx){
     int dx=abs(man[man_idx].x-stair[stair_idx].x);
     int dy=abs(man[man_idx].y-stair[stair_idx].y);
     return dx + dy;
}


void dfs(int idx);
void update();

int main(){
     int T;
     cin >> T;

     for(int tc=1; tc<=T; tc++){
          cin >> N;
          M=S=0;
          for(int i=1; i<=N; i++){
               for(int j=1; j<=N; j++){
                    cin >> map[i][j];
                    if(map[i][j]==1) man[M++]=pos(i, j);
                    if(map[i][j]>=2) stair[S++]=pos(i, j);
               }
          }
          ans=1e9;
          dfs(0);

          cout << "#"<<tc <<" " <<ans<<endl;
     }
     return 0;
}

void dfs(int idx){
     if(idx==M){
          update();
          return;
     }

     for(int i=0; i<2; i++){
          match[idx]=i;
          dfs(idx+1);
     }
}

void update(){

     int finaltime=0;
     //두 계단 중 오래 걸리는 시간이 현재 상태에서 걸리는 시간

     //시간의 흐름을 두 계단을 동시에 1초일때, 각각의 상황을 볼 필요없이
     //각각의 진행사항을 차례로 파악하면 됨
     //서로 영향을 주지않음
     for(int s_idx=0; s_idx<2; s_idx++){
          //각 계단에 대해 따로 계산
          pos &now_s=stair[s_idx];
          //같은 메모리를 다른 이름으로 불러주는 것

          int arrival_time[MAXN*2]={0,};
          int current_stair[MAXT]={0,};
          //arrival_time[t] 시간 t일 때 계단에 도착하는 사람의 수
          //최대 도착 시간 :: (0,0) ~ (N-1,N-1) 시간 :: N+N=2N시간
          //current_stair[t] : 시간 t일 때 계단을 내려가고 있는 사람의 수
          //MAXT :: 최대 도착시간 20초 + 최대 10명의 사람이 3명씩 순차적으로 동시에 최대 10개의 계단을 내려가는 시간+a

          for(int i=0; i<M; i++){
               if(match[i]==s_idx){
                    arrival_time[dist(i, s_idx)+1]++;
               }
          }

          int now_mn_t=0;
          for(int t=1; t<=20 && t<=ans; t++){
               //t==20 일때가 도착 시간 중 최대
               while(arrival_time[t]-->0){
                    int remain_time=map[now_s.y][now_s.x];
                    //현재 남은 시간
                    for(int walk_time=t; walk_time<MAXT; walk_time++){
                         //t초일때, 계단의 상태를 설정
                         if(current_stair[walk_time] < 3){
                              current_stair[walk_time]++;
                              remain_time--;

                              if(remain_time==0){
                                   now_mn_t=max(now_mn_t, walk_time+1);
                                   break;
                              }
                         }
                    }
               }
          }

          finaltime=max(finaltime, now_mn_t);
          //두 계단 중 이동이 오래걸리는 시간이 현재 상태에서의 최종 시간
     }

     ans=min(ans, finaltime);
     //현재 최소 시간과 비교
     return;


}
