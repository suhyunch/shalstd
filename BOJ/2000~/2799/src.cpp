//https://www.acmicpc.net/problem/2799
#include <iostream>
#include <string>
using namespace std;


int cnt[5];
int main(){
     int m, n;
     cin >> m >>n;

     char win[501][501];
     for(int i=0; i<5*m+1; i++){
          cin >> win[i];
     }

     for(int i=1; i<5*m+1; i+=5){
          for(int j=1; j<5*n+1; j+=5){
               for(int w=i; w<i+4; w++){
                    if(win[w][j]=='.'){
                         cnt[w-i]++;
                         break;
                    }
                    if(w==i+3) cnt[4]++;
               }
          }
     }

     for(int i=0; i<5; i++){
          cout << cnt[i]<<" ";
     }
     return 0;
}
