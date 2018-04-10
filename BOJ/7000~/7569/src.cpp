//https://www.acmicpc.net/problem/7569
#include <iostream>
using namespace std;
int M, N, H;
int box[100][100][100];


void bfs(int z, int y, int x){

}
int main(){
     cin >> M >> N >> H;

     for(int i=0; i<H; i++)
          for(int j=0; j<N; j++)
               for(int k=0; k<M; k++)
                    cin >> box[i][j][k];

     for(int i=0; i<H; i++)
          for(int j=0; j<N; j++)
               for(int k=0; k<M; k++)
                    bfs(i,j,k);


}
