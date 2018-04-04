//https://www.acmicpc.net/problem/14499
#include <iostream>
using namespace std;
#define east 1
#define west 2
#define north 3
#define south 4

int map[20][20];
class dice{
public:
     int U;//up
     int B;//bottom
     int E;//east
     int W;//west
     int N;//north
     int S;//south

     int y;
     int x;

     dice(int _U=0, int _B=0, int _E=0, int _W=0, int _N=0, int _S=0):
      U(_U), B(_B), E(_E), W(_W), N(_N), S(_S)  {}
};
int dy[5]={0, 0, 0, -1, 1};
int dx[5]={0, 1, -1, 0, 0};
int main(){
     dice d;

     int N, M, K;

     cin>> N >> M >> d.y >> d.x >> K;

     for(int i=0; i<N; i++){
          for(int j=0; j<M; j++){
               cin >> map[i][j];
          }
     }
     while(K-->0){
          int dir;
          cin >> dir;

          int ny=d.y+dy[dir];
          int nx=d.x+dx[dir];

          if(ny>=0 && ny<N && nx>=0 && nx<M){
               d.y=ny;
               d.x=nx;
                    int tmp;
                    if(dir==east){
                         tmp=d.W;
                         d.W=d.B;
                         d.B=d.E;
                         d.E=d.U;
                         d.U=tmp;
                    }
                    else if(dir==west){
                         tmp=d.W;
                         d.W=d.U;
                         d.U=d.E;
                         d.E=d.B;
                         d.B=tmp;
                    }
                    else if(dir==north){
                         tmp=d.B;
                         d.B=d.N;
                         d.N=d.U;
                         d.U=d.S;
                         d.S=tmp;
                    }
                    else {
                         tmp=d.S;
                         d.S=d.U;
                         d.U=d.N;
                         d.N=d.B;
                         d.B=tmp;
                    }

                    cout << d.U << endl;

                    if(map[d.y][d.x]==0){
                         map[d.y][d.x]=d.B;
                    }
                    else{
                         d.B=map[d.y][d.x];
                         map[d.y][d.x]=0;
                    }
               }

     }
     return 0;
}
