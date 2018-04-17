//https://www.acmicpc.net/problem/15685
#include <iostream>
#include <vector>
using namespace std;

#define right 0
#define up 1
#define left 2
#define down 3

int dy[4]={0,-1, 0, 1};
int dx[4]={1, 0,-1, 0};

bool map[101][101];

int main(){
     int N;
     cin >> N;
     int cnt=0;
     for(int i=0; i<N; i++){
          int x, y, d, g;
          cin >> x >> y >> d >>g;

          map[y][x]=1;
          map[y+dy[d]][x+dx[d]]=1;
          vector<int> st;
          st.push_back(d);
          st.push_back(d);

          int tmpy=y+dy[d];
          int tmpx=x+dx[d];
          int l=1;
          for(int ge=1; ge<=g; ge++){
               for(int j=l; j>0; j--){
                    int nd=(st[j]+1)%4;
                    int ny=tmpy+dy[nd];
                    int nx=tmpx+dx[nd];
                    map[ny][nx]=1;
                    st.push_back(nd);
                    tmpy=ny;
                    tmpx=nx;
               }
               l=l<<1;
          }
     }

     for(int i=0; i<100; i++){
          for(int j=0; j<100; j++){
               if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1])
                    cnt++;
          }
     }

     cout << cnt;

}
