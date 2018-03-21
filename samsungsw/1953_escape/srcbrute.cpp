#include <iostream>
using namespace std;
int N, M, R, C, L;
int map[50][50];
bool prob_even[50][50];//짝수 시간 후 가능한 위치
bool prob_odd[50][50];//홀수 시간 후 가능한 위치
int dy[4]={-1, 0, 1, 0};
int dx[4]={0, 1, 0, -1};
void input();
int solve(int y, int x);
bool IsPossible(int pos, int y, int x);
int main(){
     int tc;
     scanf("%d", &tc);

     for(int T=1; T<=tc; T++){
          input();
          printf("#%d %d\n",T,solve(R, C));
     }
}

void input(){
     scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               scanf("%d", map[i]+j);
               prob_odd[i][j]=0;
               prob_even[i][j]=0;
          }
     }
}

int solve(int y, int x){
     prob_odd[y][x]=true; // 1시간 후 최초 위치
     int prevcnt=1; // 현재 검색할 횟수
     int tmpcnt=0; // 다음에 검색할 횟수
     int now;
     cout << endl;
     for(int T=2; T<=L; T++){
          cout << T-1 << endl;
          bool chk=0;
          if(T%2){//홀수 시간 후
               for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                         if(prob_even[i][j] && prevcnt>0){
                              if(!prob_odd[i][j]) tmpcnt++;
                              prob_odd[i][j]=true;
                              prevcnt--;
                              now=map[i][j];
                              switch(now){
                              case 1:{
                                   for(int k=0; k<4; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                              case 2:{
                                   for(int k=0; k<3; k++){
                                        if(k==1) continue;
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                              case 3:{
                                   for(int k=1; k<4; k++){
                                        if(k==2) continue;
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                              case 4:{
                                   for(int k=0; k<2; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                              case 5:{
                                   for(int k=1; k<3; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                              case 6:{
                                   for(int k=2; k<4; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_odd[ny][nx]) tmpcnt++;
                                             prob_odd[ny][nx]=true;
                                        }
                                   }
                              }
                              break;
                             case 7:{
                                  if(map[i+dy[0]][j+dx[0]]>0 && IsPossible(0, i, j)){
                                       if(!prob_odd[i+dy[0]][j+dx[0]]) tmpcnt++;
                                       prob_odd[i+dy[0]][j+dx[0]]=true;
                                  }
                                  if(map[i+dy[3]][j+dx[3]]>0 && IsPossible(3, i, j)){
                                       if(!prob_odd[i+dy[3]][j+dx[3]]) tmpcnt++;
                                       prob_odd[i+dy[3]][j+dx[3]]=true;
                                  }
                              }
                              break;
                         }
                    }
                         if(!prevcnt){
                              chk=1;
                              break;
                         }
                    }
                    if(chk) break;
               }
               if(T==L) {
                    return tmpcnt;
               }
               for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                         prob_even[i][j]=false;
                         cout << prob_odd[i][j] <<" ";
                    }cout << endl;
               }
               cout << endl;
          }
          else{// 짝수 시간 후
               for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                         if(prob_odd[i][j] && prevcnt>0){
                              if(!prob_even[i][j]) tmpcnt++;
                              prob_even[i][j]=true;
                              prevcnt--;
                              now=map[i][j];
                              switch(now){
                              case 1:{
                                   for(int k=0; k<4; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }
                                   }
                                   break;
                              }
                              case 2:{
                                   for(int k=0; k<3; k++){
                                        if(k==1) continue;
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }
                                   }
                                   break;
                              }
                              case 3:{
                                   for(int k=1; k<4; k++){
                                        if(k==2) continue;
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }
                                   }
                                   break;
                              }
                              case 4:{
                                   for(int k=0; k<2; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }
                                   }
                                   break;
                              }
                              case 5:{
                                   for(int k=1; k<3; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }
                                   }
                                   break;
                              }
                              case 6:{
                                   for(int k=2; k<4; k++){
                                        int ny=i+dy[k];
                                        int nx=j+dx[k];
                                        if(map[ny][nx]>0 && IsPossible(k, i, j)){
                                             if(!prob_even[ny][nx]) tmpcnt++;
                                             prob_even[ny][nx]=true;
                                        }

                                   }
                                   break;
                              }
                              case 7:{
                                   if(map[i+dy[0]][j+dx[0]]>0 && IsPossible(0, i, j)){
                                        if(!prob_even[i+dy[0]][j+dx[0]]) tmpcnt++;
                                        prob_even[i+dy[0]][j+dx[0]]=true;
                                   }
                                   if(map[i+dy[3]][j+dx[3]]>0 && IsPossible(3, i, j)){
                                        if(!prob_even[i+dy[3]][j+dx[3]]) tmpcnt++;
                                        prob_even[i+dy[3]][j+dx[3]]=true;
                                   }
                              }
                              break;
                         }
                         }
                         if(!prevcnt){
                              chk=1;
                              break;
                         }

                    }
                    if(chk) break;
               }
               if(T==L) {
                    return tmpcnt;
               }
               for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                         prob_odd[i][j]=false;
                         cout << prob_even[i][j] <<" ";
                    }cout <<endl;
               }
               cout << endl;
          }

          prevcnt=tmpcnt;
          tmpcnt=0;


     }return prevcnt;
}

bool IsPossible(int pos, int y, int x){
     int ny=y+dy[pos];
     int nx=x+dx[pos];
     if(pos==0){
          if(map[ny][nx]==1 || map[ny][nx]==2 || map[ny][nx]==5 || map[ny][nx]==6)
               return true;
          else return false;
     }
     else if(pos==1){
          if(map[ny][nx]==1 || map[ny][nx]==3 || map[ny][nx]==6 || map[ny][nx]==7)
               return true;
          else return false;
     }
     else if(pos==2){
          if(map[ny][nx]==1 || map[ny][nx]==2 || map[ny][nx]==4 || map[ny][nx]==7)
               return true;
          else return false;
     }
     else if(pos==3){
          if(map[ny][nx]==1 || map[ny][nx]==3 || map[ny][nx]==4 || map[ny][nx]==5)
               return true;
          else return false;
     }

}
