#include <iostream>
#include <queue>
using namespace std;

class cus{
public :
     int k;
     int t;
     cus(int _k=0, int _t=0):k(_k),t(_t){}
};

class repcus{
public :
     int idx;
     int k;
     int t;
     repcus(int _idx=0, int _k=0, int _t=0) : idx(_idx), k(_k), t(_t) {}
};//정비 창구 대기 큐 원소 구조체
int N, M, K, A, B;
int a[10];
int b[10];
//접수창구, 정비창구 처리시간
cus rec[10];
cus rep[10];
//현재 접수(rec), 정비(rep) 창구 이용 고객 정보
cus recq[1001];
repcus repq[1001];
//접수창구, 정비창구 대기 큐

void input(){
     cin >> N >> M >> K >> A >> B;
     for(int i=1; i<=N; i++) cin >> a[i];
     for(int i=1; i<=M; i++) cin >> b[i];
     for(int i=1; i<=K; i++) {
          int t0;
          cin >> t0;
          recq[i].t=t0;
          recq[i].k=i;
     }
}

void sortrec(){
     //recq의 t를 시간 순으로 정렬, 도착 순으로 고객 번호를 부여받기 때문에
     //k는 그대로
     for(int i=1; i<K; i++){
          int tmp=i;
          int tmpt=recq[i].t;
          int idx=i;
          int mn=tmpt;
          for(int j=i; j<=K; j++){
               if(recq[j].t<mn){
                    mn=recq[j].t;
                    idx=j;
               }
          }

          recq[tmp].t=mn;
          recq[idx].t=tmpt;
     }
}

void solve(){
     int res=0; // 고객 번호 총합

     int rec_idx=1;
     int c2p_idx=0;
     int rep_idx=0;

     for(int t1me=recq[1].t, cnt=1; cnt<=K; t1me++){
          //첫 손님 도착 시간부터 시작, cnt는 손님 수
          //cout << " now time is " << t1me <<endl;
          //접수창구
          for(int i=1; i<=N; i++){
               if(rec[i].t > 0){ // i 창구에 접수 중인 고객 존재
                    rec[i].t--;//t1me 증가마다 시간 감소
                    if(rec[i].t==0){ // 접수 완료시
                         repq[c2p_idx++]={i, rec[i].k, t1me};
                         // 이용한 접수창구, 고객 번호, 정비 창구 이동시간
                    }
               }

               if(rec[i].t == 0){ //i번 창구가 이용 가능할 때
                    if(rec_idx <= K && recq[rec_idx].t<t1me){
                         //대기 창구에 고객 존재, 우선순위가 높은(도착 시간이 빠른) 손님이 도착
                         cus now = recq[rec_idx++];
                         rec[i]= { now.k, a[i] };
                         //i번째 창구 고객의 번호, 걸리는 시간 a[i]
                    }
               }
          }
          //for(int i=1; i<=N; i++)  cout << rec[i].k << " " << rec[i].t <<endl;
          //정비창구
          for(int j=1; j<=M; j++){
               if(rep[j].t > 0){ //j 창구에 접수 중인 고객 존재
                    rep[j].t--;
                    if(rep[j].t==0) cnt++;
               }
               if(rep[j].t==0){// 정비창구가 이용가능한 상태
                    if(rep_idx < c2p_idx){ //정비 창구 대기큐 고객 수가 현재 접수 마친 고객 수보다 적을 때
                         repcus now = repq[rep_idx++];
                         rep[j]={ now.k, b[j] };

                         if(now.idx==A && j==B) res+=now.k;
                    }
               }
          }
          //for(int i=1; i<=M; i++)  cout << rep[i].k << " " << rep[i].t <<endl;
     }
     //탐색 끝

     if(res==0) cout << "-1" << endl;
     else cout << res << endl;
}
int main(){
     int tc;
     cin >> tc;

     for(int T=1; T<=tc; T++){
          input();
          sortrec();
          cout << "#" << T << " ";
          solve();
     }
}
