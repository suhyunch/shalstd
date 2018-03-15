#include <iostream>
using namespace std;
bool map[20][20];
int cost_k[50]={0,1,};
int N, M, mx;

int input(){
     cin >> N >> M;
	int cnt=0;
     for(int i=0; i<N; i++){
          for(int j=0; j<N; j++){
               cin >> map[i][j];
              if(map[i][j]) cnt++;
          }
     }
    return cnt;
}
void find(int y, int x, int fork){
     int cnt;
     for(int K=1; K<=fork; K++){
          cnt=0;
          int a=0;
          for(int i=y-(K-1); i<=y; i++, a++){
               for(int j=x-a; j<=x+a; j++){
                    if(i<0 || i>N-1 || j<0 || j>N-1) continue;
                    if(map[i][j]) cnt++;
               }
          }
          for(int i=y+1; i<=y+(K-1); i++, a--){
               for(int j=x-a+2; j<=x+a-2; j++){
                    if(i<0 || i>N-1 || j<0 || j>N-1) continue;
                    if(map[i][j]) cnt++;
               }
          }

        	if(cost_k[K]<=cnt*M && mx<cnt) mx=cnt;
     }
}
int main(){
     int tc;
     cin >> tc;


     for(int T=1; T<=tc; T++){
          int num=input();
          int fork=0;
          mx=0;
          for(int k=2; k<=50; k++) {
              cost_k[k]=k*k+(k-1)*(k-1);
              if(num*M >= cost_k[k]) fork=k;
              else break;
          }
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    find(i, j , fork);
               }
          }
          cout <<"#" << T << " " << mx << endl;
     }
    return 0;
}
