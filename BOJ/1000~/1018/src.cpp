//https://www.acmicpc.net/problem/1018
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, mn;
char map[50][50];

void input(){
     cin >> N >> M;

     for(int i=0; i<N; i++)
          cin >> map[i];
}

int painting_white_fst(int y, int x){
     int cnt=0;
     for(int i=y; i<y+8; i++){
          for(int j=x; j<x+8; j++){
               if((y%2)==(i%2)){
                    if((x%2)==(j%2)){ if(map[i][j]=='B') cnt++;}
                    else { if(map[i][j]=='W') cnt++;}
               }
               else {
                    if((x%2)==(j%2)){ if(map[i][j]=='W') cnt++;}
                    else { if(map[i][j]=='B') cnt++;}
               }
          }
     }
     return cnt;
}

int find(){
     int ans=66;
     for(int i=0; i<=N-8; i++){
          for(int j=0; j<=M-8; j++){
               int tmp=painting_white_fst(i,j);
               mn=min(tmp,64-tmp);
               ans=min(ans,mn);
          }
     }
     return ans;
}

int main(){
     input();

     cout << find();
}
