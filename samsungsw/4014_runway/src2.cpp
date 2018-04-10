#include <iostream>
using namespace std;
int N, X;
int map[20][20];

void input();
bool vertical(int x);
bool horizontal(int y);

int main(){
     int tc;
     scanf("%d",&tc);

     for(int T=1; T<=tc; T++){
          int ans=0;
          input();

          for(int i=0; i<N; i++){
               ans+=vertical(i);
               ans+=horizontal(i);
          }

          printf("#%d %d\n",T, ans);
     }
     return 0;
}

void input(){
     scanf("%d %d",&N, &X);
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               scanf("%d", map[i]+j);
          }
     }
     return;
}

bool vertical(int x){
     int tmp=map[0][x];
     int l=1;//같은 높이인 길이
     for(int i=1; i<N; i++){
          if(map[i][x]!=tmp){
               if(tmp==map[i][x]-1 || tmp==map[i][x]+1){
                    if(l<X) return false;
                    tmp=map[i][x];
                    l=1;
               }
               else {
                    return false;
               }
          }
          else l++;
     }
     cout << "veritcal : "<< x <<endl;
     return true;
}
bool horizontal(int y){
     int tmp=map[y][0];
     int l=1;//같은 높이인 길이
     for(int i=1; i<N; i++){
          if(map[y][i]!=tmp){
               if(tmp==map[y][i]-1 || tmp==map[y][i]+1){
                    if(l<X) return false;
                    tmp=map[y][i];
                    l=1;
               }
               else {
                    return false;
               }
          }
          else l++;
     }
     cout << "horizontal : "<< y <<endl;
     return true;
}
