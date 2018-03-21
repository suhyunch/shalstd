#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int N, M, R, C, L;
int map[50][50];
bool visited[50][50];//짝수 시간 후 가능한 위치
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
          cout << endl;
          printf("#%d %d\n",T,solve(R, C));
     }
}

void input(){
     scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               scanf("%d", map[i]+j);
               visited[i][j]=false;
          }
     }
     return;
}

int solve(int y, int x){
     visited[y][x]=true; // 1시간 후 최초 위치
     queue<pair<int, int> > s;
     s.push(make_pair(y, x));
     int ans=0;
     int cnt0=1;
     int cnt2=0;
     for(int i=1;i<L; i++){
          while(cnt0-->0){
               cout << i << " :: " << cnt0 <<endl;
               int nowy=s.front().first;
               int nowx=s.front().second;
               s.pop();
               int now=map[nowy][nowx];
               switch(now){
                    case 1:{
                         for(int k=0; k<4; k++){
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]) {
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 2:{
                         for(int k=0; k<3; k++){
                              if(k==1) continue;
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]) {
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 3:{
                         for(int k=1; k<4; k++){
                              if(k==2) continue;
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]){
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 4:{
                         for(int k=0; k<2; k++){
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]) {
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 5:{
                         for(int k=1; k<3; k++){
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]){
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 6:{
                         for(int k=2; k<4; k++){
                              int ny=nowy+dy[k];
                              int nx=nowx+dx[k];
                              if(map[ny][nx]>0 && IsPossible(k, nowy, nowx)){
                                   if(!visited[ny][nx]){
                                        s.push(make_pair(ny, nx));
                                        cnt2++;
                                   }
                                   visited[ny][nx]=true;
                              }
                         }
                    }
                    break;
                    case 7:{
                         if(map[nowy+dy[0]][nowx+dx[0]]>0 && IsPossible(0, nowy, nowx)){
                              if(!visited[nowy+dy[0]][nowx+dx[0]]) {
                                   s.push(make_pair(nowy+dy[0], nowx+dx[0]));
                                   cnt2++;
                              }
                              visited[nowy+dy[0]][nowx+dx[0]]=true;
                         }
                         if(map[nowy+dy[3]][nowx+dx[3]]>0 && IsPossible(3, nowy, nowx)){
                              if(!visited[nowy+dy[3]][nowx+dx[3]]) {
                                   cout << "i dont know  " << nowy+dy[3] << " , " <<nowx+dx[3] <<endl;
                                   s.push(make_pair(nowy+dy[3], nowx+dx[3]));
                                   cnt2++;
                              }
                              cout << "i dont know2  " << nowy+dy[3] << " , " <<nowx+dx[3] <<endl;
                              visited[nowy+dy[3]][nowx+dx[3]]=true;
                         }
                    }
                    break;
               }
               for(int i=0; i<N; i++){
                    for(int j=0; j<M; j++){
                         cout << visited[i][j] <<" ";
                    }cout <<endl;
               }
               cout << cnt2 << endl;

          }
          cnt0=cnt2;
          cout << cnt2 << endl;
          cnt2=0;

     }

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               if(visited[i][j]) ans++;
          }
     }
     return ans;
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
