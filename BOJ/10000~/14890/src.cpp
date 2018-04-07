#include <iostream>
#include <cstdio>
using namespace std;
int N, X;
int margin;
int map[200][200];
void input();
bool vertical(int x);
bool horizontal(int y);
bool Can(int x, int i, int mode);

int main(){
     int ans=0;
     input();

     for(int i=0; i<N; i++){
          margin=-1;
          ans+=vertical(i);
          margin=-1;
          ans+=horizontal(i);
     }

     cout << ans;
     return 0;
}

void input(){
     cin >> N >> X;
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               scanf("%d", map[i]+j);
          }
     }
     return;
}

bool vertical(int x){
     int tmp=map[0][x];
     for(int i=1; i<N; i++){
          if(map[i][x]!=tmp){
               if(tmp==map[i][x]-1){
                    if(!Can(x, i, 0)) {
                         return false;
                    }
                    else{
                         tmp=map[i][x];
                    }
               }
               else if(tmp==map[i][x]+1){
                    if(!Can(x, i, 1)) {
                         return false;
                    }
                    else{
                         i+=X-1;
                         tmp=map[i][x];
                    }
               }
               else return false;
          }
     }
     return true;
}
bool horizontal(int y){
     int tmp=map[y][0];
     for(int i=1; i<N; i++){
          if(map[y][i]!=tmp){
               if(tmp==map[y][i]-1){
                    if(!Can(y, i, 2)) return false;
                    else{
                         tmp=map[y][i];
                    }
               }
               else if(tmp==map[y][i]+1){
                    if(!Can(y, i, 3)) {
                         return false;
                    }
                    else{
                         i+=X-1;
                         tmp=map[y][i];
                    }
               }
               else return false;
          }
     }
     return true;
}

bool Can(int x, int i, int mode){
     int tmp;
     if((mode==0||mode==2) && i-X<=margin) return false;
     if((mode==1||mode==3) && i-1+X>=N) return false;
     if(mode==0){
          tmp=map[i][x]-1;
          for(int j=i-X; j<i; j++){
               if(map[j][x]!=tmp) return false;
          }
          margin=i-1;
          return true;
     }
     else if(mode==1) {
          tmp=map[i][x];
          for(int j=i; j<i+X; j++){
               if(map[j][x]!=tmp) return false;
          }
          margin=i+X-1;
          return true;
     }
     else if(mode==2){
          tmp=map[x][i]-1;
          for(int j=i-X; j<i; j++){
               if(map[x][j]!=tmp) return false;
          }
          margin=i-1;
          return true;
     }
     else if(mode==3){
          tmp=map[x][i];
          for(int j=i; j<i+X; j++){
               if(map[x][j]!=tmp) return false;
          }
          margin=i+X-1;
          return true;
     }
}
