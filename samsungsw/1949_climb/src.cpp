#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int N,K;
int map[8][8];

int dy[4]={0, 0, 1, -1};
int dx[4]={1, -1, 0, 0};


void input();

int main(){
     int tc;
     scanf("%d",&tc);

     for(int T=1; T<=tc; T++){
          input();
          
     }
}

void input(){
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               scanf("%d", map[i]+j);
          }
     }
}
