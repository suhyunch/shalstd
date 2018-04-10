//https://www.acmicpc.net/problem/2042
#include <iostream>
using namespace std;
int map[1025][1025];
int sum[1025][1025];
int main(){
     int N, M, K;
     cin >> N >> M >> K;

     for(int i=1; i<=N; i++){
          for(int j=1; j<=N; j++){
               int a;
               cin >> a;
               map[i][j]=a;
               sum[i][j]=a+sum[i][j-1];
          }
     }


     while(M-->0){
          bool w;
          cin >> w;

          if(w){
               int x1, y1, x2, y2;
               cin >> x1 >> y1 >> x2 >> y2;

               int ans=0;
               for(int i=y1; i<=y2; i++){
                    ans+=(sum[i][x2]-sum[i][x1-1]);
               }
               cout << ans << endl;
          }

          else{
               int x, y, c;
               cin >> x >> y >> c;
               int sub=map[y][x]-c;
               map[y][x]=c;

               if(sub!=0){
                    for(int i=x; i<=N; i++){
                         sum[y][i]-=sub;
                    }
               }
          }
     }


     return 0;
}
