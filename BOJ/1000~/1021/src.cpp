//https://www.acmicpc.net/problem/1021
#include <iostream>
using namespace std;
int queue[51];
int N,M;
void find(int x, int total);
void init();
void rotR(int cnt, index);
void rotL(int cnt, index);

int main(){
     int ans=0;
     cin >> N >> M;

     init();

     for(int i=0; i<M; i++){
          int x;
          cin >> queue;

          int tmp = find(x, N); // 현위치
          if(N-tmp+1 < tmp-1) {
               ans+=N-tmp+1;
               rotR(N-tmp+1, tmp);
          }
          else {
               ans+=tmp-1;
               rotL(tmp-1, tmp);
          }
     }
}

void init(){
     for(int i=1; i<=N; i++)
          queue[i]=i;
}

int find(int x, int total){
     int index;
     for(int i=1; i<=total; i++)
          if(queue[i]==x) index=i;
     return index;
}

void rotR(int cnt, index){
     int tmp[51];
     for(int i=1; i<N; i++){
          tmp[i]=
     }
}
