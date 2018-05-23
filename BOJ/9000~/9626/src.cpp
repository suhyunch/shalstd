//https://www.acmicpc.net/problem/9626
#include <iostream>
using namespace std;
char map[10][10];
int main(){
     int m,n;
     int u,l,r,d;
     cin >> m >> n;
     cin >> u >> l >> r >> d;

     for(int i=0; i<m; i++){
          cin >> map[i];
     }
     for(int i=0; i<u; i++){
          for(int j=0; j<l+n+r; j++){
               if(i%2==0){
                    if(j%2==0) cout << '#';
                    else cout <<'.';
               }
               else{
                    if(j%2==1) cout << '#';
                    else cout <<'.';
               }
          }cout <<'\n';
     }

     for(int i=0; i<m; i++){
          int j=0;
          for(j=0; j<l; j++){
               if((u+i)%2==0){
                    if(j%2==0) cout << '#';
                    else cout <<'.';
               }
               else{
                    if(j%2==1) cout << '#';
                    else cout <<'.';
               }
          }
          for(; j<l+n; j++)
               cout << map[i][j-l];
          for(;j<l+n+r; j++){
               if((u+i)%2==0){
                    if(j%2==0) cout << '#';
                    else cout <<'.';
               }
               else{
                    if(j%2==1) cout << '#';
                    else cout <<'.';
               }
          }
          cout <<'\n';
     }

     for(int i=0; i<d; i++){
          for(int j=0; j<l+n+r; j++){
               if((u+m+i)%2==0){
                    if(j%2==0) cout << '#';
                    else cout <<'.';
               }
               else{
                    if(j%2==1) cout << '#';
                    else cout <<'.';
               }
          }cout <<'\n';
     }
     return 0;
}
