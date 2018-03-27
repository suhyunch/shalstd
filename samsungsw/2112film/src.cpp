#include <iostream>
using namespace std;
int D,W,K;
bool film[14][21];//오리지날 필름
int match[21];// match[i]=j i번째 열이 j로 약물처리 됨 :: 0 X, 1 A, 2 B
int mn;
void input();
void process(int idx, int kindofchemical, int cnt);
void test(int cnt);

void init(){
    for(int i=0; i<21; i++){
        match[i]=0;
        for(int j=0; j<14; j++){
            film[j][i]=0;
        }
    }
    return;
}

int main(){

     int tc;
     scanf("%d", &tc);

     for(int T=1; T<=tc; T++){
         init();
          input();
          mn=K;
          match[0]=0;
          process(0, 0, 0);//약품처리
          match[0]=1;
          process(0, 1, 1);
          match[0]=2;
          process(0, 2, 1);
          printf("#%d %d\n", T, mn);
     }
     return 0;
}

void input(){
     scanf("%d %d %d", &D, &W, &K);

     for(int i=0; i<D; i++){
          for(int j=0; j<W; j++){
               scanf("%d", &film[i][j]);
          }
     }
}

void process(int idx,int kindofchemical, int cnt){
     if (cnt>K || cnt>mn ) return;
     if(idx==D){
          test(cnt);
          return;
     }

      match[idx]=0;
      process(idx+1, 0, cnt);
      if( idx < D && cnt+1 < mn){
           match[idx]=1;
           process(idx+1, 1, cnt+1);
           match[idx]=2;
           process(idx+1, 2, cnt+1);
      }
}

void test(int cnt){
	if(cnt>K) return;
    //match 값에 따라약품 처리한 배열
     int processed[14][21];
     //int cnt=0;
     for(int i=0; i<D; i++){
          if(match[i]==0) {
               for(int j=0; j<W; j++) processed[i][j]=film[i][j];
          }
          else if(match[i]==1){
               for(int j=0; j<W; j++) processed[i][j]=0;
               //cnt++;
          }
          else if(match[i]==2){
               for(int j=0; j<W; j++) processed[i][j]=1;
               //cnt++;
          }
     }
     //test하기


     for(int i=0; i<W; i++){
          int chk=0;
          bool now=0;
          for(int j=0; j<D; j++){
               if(chk>=K) continue;

               if(now!=processed[j][i]) {
                   if(j>D-K) return;
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
