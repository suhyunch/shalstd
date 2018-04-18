//https://www.acmicpc.net/problem/15683
#include <iostream>
using namespace std;

int n, m, tv, mn;
int map[8][8];
int tvpos[8][3];
void input();
void dfs(int idx);
void update();
int main(){
     input();

     int num=4;
     if(map[tvpos[0][0]][tvpos[0][1]]==2) num=2;
     else if(map[tvpos[0][0]][tvpos[0][1]]==5) num=1;

     mn=64;
     for(int i=0; i<num; i++){
          tvpos[0][2]=i;
          dfs(1);
     }

     cout << mn;
    return 0;
}


void input(){
     cin >> n >> m;

     for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
               cin >> map[i][j];
               if(0<map[i][j]&& map[i][j]<6){
                    tvpos[tv][0]=i;
                    tvpos[tv][1]=j;
                    tv++;
               }
          }
     }
     return;
}

void dfs(int idx){
     if(idx>=tv){
          update();
          return;
     }

     int num=4;
     if(map[tvpos[idx][0]][tvpos[idx][1]]==2) num=2;
     else if(map[tvpos[idx][0]][tvpos[idx][1]]==5) num=1;

     for(int i=0; i<num; i++){
          tvpos[idx][2]=i;
          dfs(idx+1);
     }
     return;
}

void update(){
     int cnt=0;
     int map_tmp[8][8];
     for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
               map_tmp[i][j]=map[i][j];
          }
     }

     for(int i=0; i<tv; i++){
          int y=tvpos[i][0];
          int x=tvpos[i][1];
          switch (map[y][x]) {
               case 1:
                    if(tvpos[i][2]==0){ //상
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                    }
                    else if(tvpos[i][2]==1){//하
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                    }
                    else if(tvpos[i][2]==2){//좌
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==3){//우
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    break;
               case 2:
                    if(tvpos[i][2]==0){//상하
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                    }
                    else if(tvpos[i][2]==1){//좌우
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    break;
               case 3:
                    if(tvpos[i][2]==0){//상좌
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==1){//상우
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==2){//하좌
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==3){//하우
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    break;
               case 4:
                    if(tvpos[i][2]==0){//좌상우
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==1){//상우하
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                    }
                    else if(tvpos[i][2]==2){//우하좌
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                         for(int j=x; j<m; j++){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                    }
                    else if(tvpos[i][2]==3){//하좌상
                         for(int j=y; j<n; j++){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                         for(int j=x; j>=0; j--){
                              if(map[y][j]==6) break;
                              map_tmp[y][j]=1;
                         }
                         for(int j=y; j>=0; j--){
                              if(map[j][x]==6) break;
                              map_tmp[j][x]=1;
                         }
                    }
                    break;
               case 5:
                    for(int j=y; j>=0; j--){
                         if(map[j][x]==6) break;
                         map_tmp[j][x]=1;
                    }
                    for(int j=y; j<n; j++){
                         if(map[j][x]==6) break;
                         map_tmp[j][x]=1;
                    }
                    for(int j=x; j>=0; j--){
                         if(map[y][j]==6) break;
                         map_tmp[y][j]=1;
                    }
                    for(int j=x; j<m; j++){
                         if(map[y][j]==6) break;
                         map_tmp[y][j]=1;
                    }
                    break;
          }
     }
     for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){
               if(map_tmp[i][j]==0) cnt++;
          }
     }

     if(cnt<mn)
          mn=cnt;
     return;
}
