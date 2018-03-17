#include <iostream>
using namespace std;
int D,W,K;
bool film[13][20];//오리지날 필름
int match[20];// match[i]=j i번째 열이 j로 약물처리 됨 :: 0 X, 1 A, 2 B
int mn=25;
void input();
void process(int idx);
void test();


int main(){

     int tc;
     scanf("%d", &tc);

     for(int T=1; T<=tc; T++){
          input();
          mn=25;
          process(0);//약품처리
          printf("#%d %d\n", T, mn);
     }
     return 0;
}

void input(){
     scanf("%d %d %d", &D, &W, &K);

     for(int i=0; i<D; i++){
          for(int j=0; j<W; j++){
               scanf("%d", film[i]+j);
          }
     }
}

void process(int idx){
     if(idx==D){
          test();
          return;
     }

     for(int i=0; i<3; i++){
          match[idx]=i;
          process(idx+1);
     }
}

void test(){
     //match 값에 따라약품 처리한 배열
     bool processed[13][20]={0,};
     int cnt=0;
     for(int i=0; i<D; i++){
          if(match[i]==0) {
               for(int j=0; j<W; j++) processed[i][j]=film[i][j];
          }
          else if(match[i]==1){
               for(int j=0; j<W; j++) processed[i][j]=0;
               cnt++;
          }
          else if(match[i]==2){
               for(int j=0; j<W; j++) processed[i][j]=1;
               cnt++;
          }
     }
     //test하기

     for(int i=0; i<W; i++){
          int chk=0;
          bool now=0;
          for(int j=0; j<D; j++){
               if(chk==K) continue;

               if(now!=processed[j][i]) {
                    now=processed[j][i];
                    chk=1;
               }
               else chk++;
               if(j==D-1){
                    if(chk<K) return;
               }

          }

          if(i==W-1){
               if(mn>cnt) {
                    mn=cnt;
               }
          }
     }

     return;
}
