#include <iostream>
#include <math.h>
using namespace std;

const int MAXN=11;
const int MAXT=MAXN*2+MAXN*MAXN;
//이동시간 2N+10명*최장계단길이10 여유+1?
struct PT{
     int r,c;
     PT() {}
     PT(int r, int c) : r(r), c(c) {}
} man[MAXN], stair[2];

int N, M, S;
//N 방의 한변의 길이
//M 사람의 수
//S 계단의 수 , =2
int map[MAXN][MAXN];
int match[MAXN];
int ans;

int dist(int man_idx, int stair_idx){
     int dx=abs(man[man_idx].r-stair[stair_idx].r);
     int dy=abs(man[man_idx].c-stair[stair_idx].c);
     return dx + dy;
}

void update(){
     //각 사람이 어느 계단을 이용할 지 모두 정해졌을 때에 필요한 시간을 계산하는 함수

     int total_min_time=0;

     for(int stair_idx=0; stair_idx<2; stair_idx++){
          PT &now_stair=stair[stair_idx];
          int arrival_time[MAXN*2]={0,};
          //arrival_time[t] 시간 t일 때 계단에 도착하는 사람의 수
          //최대 도착 시간 :: (0,0) ~ (N-1,N-1) 시간 :: N+N=2N시간

          int current_stair[MAXT]={0,};
          //current_stair[t] : 시간 t일 때 계단을 내려가고 있는 사람의 수

          for(int man_idx = 0; man_idx < M; man_idx++){
               if(match[man_idx] == stair_idx){
                    arrival_time[dist(man_idx, stair_idx)+1]++;
               }
          }
          int now_min_time=0;
          //계단에 도착하는 시간 오른차순으로 각 사람이 계단을 내려가도록 시뮬레이션
          for(int t=1; t<=20; t++){
               while(arrival_time[t]-->0){
                    int remain_time=map[now_stair.r][now_stair.c];
                    for(int walk_time=t; walk_time<MAXT; walk_time++){
                         if(current_stair[walk_time] < 3){
                              current_stair[walk_time]++;
                              remain_time--;

                              if(remain_time==0){
                                   now_min_time=max(now_min_time, walk_time+1);
                                   break;
                              }
                         }
                    }
               }
          }
          total_min_time=max(total_min_time, now_min_time);
     }
     ans=min(ans, total_min_time);
}

void dfs(int idx){
     if(idx==M){
          update();
          return;
     }
     for(int stair_idx=0; stair_idx<2; stair_idx++){
          match[idx]=stair_idx;
          dfs(idx+1);
     }
}

int main(){
     int T;
     cin >> T;

     for(int tc=1; tc<=T; tc++){
          cin >>N;
          M=S=0;
          for(int i=1; i<=N; i++){
               for(int j=1; j<=N; j++){
                    cin >> map[i][j];
                    if(map[i][j]==1) man[M++]=PT(i, j);
                    if(map[i][j]>=2) stair[S++]=PT(i, j);
               }
          }
          ans=1e9;
          dfs(0);

          cout << "#"<<tc <<" " <<ans<<endl;
     }
}
