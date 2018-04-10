#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int T, N;
int map[10][10];
class step{
public:
     int y;
     int x;
     int l;
};
vector<pair<int, int> > k0;
vector<pair<int, int> > k1;
step step0;
step step1;
int order[10];

int abs(int a, int b){
     return a>b ? a-b : b-a;
}

void update(){
     //시간 계산하기
     for(int t=0; t<)
}
void dfs(int M, int pidx){
     if(pidx==M){
          update();
          return;
     }
     for(int stair_index=0; stair_index<2; stair_index++){
          order[pidx]=stair_index;
          dfs(M, pidx+1);
     }
}

int main(){
     cin >> T;
     for(int TC=1; TC<=T; TC++){
          cin >> N;


          int pp[10][2];//person position
          int pc=0;//person count
          bool sc=0;//step count
          for(int i=0; i<N; i++){
               for(int j=0; j<N; j++){
                    cin >> map[i][j];
                    if(map[i][j]==1){
                         pp[pc][0]=i;
                         pp[pc++][1]=j;
                    }
                    if(map[i][j]>=2){
                         if(sc==0){
                              step0.y=i;
                              step0.x=j;
                              step0.l=map[i][j];
                              sc=true;
                         }
                         else{
                              step1.y=i;
                              step1.x=j;
                              step1.l=map[i][j];
                         }
                    }
               }
          }

          for(int i=0; i<pc; i++){
               k0.push_back(make_pair(abs(pp[i][0],step0.y)+abs(pp[i][1],step0.x),i));
               k1.push_back(make_pair(abs(pp[i][0],step1.y)+abs(pp[i][1],step1.x),i));
          }
          sort(k0.begin(), k0.end());
          sort(k1.begin(), k1.end());

          for(int i=0; i<pc; i++){
               cout << i << " : " << pp[i][0] << " " << pp[i][1] << endl;
          }
          for(int i=0; i<pc; i++){
               cout << k0[i].first << " " << k0[i].second << endl;
          }
          cout << endl;
          for(int i=0; i<pc; i++){
               cout << k1[i].first << " " << k1[i].second << endl;
          }

cout <<" step0 - y : " << step0.y << " , x : " << step0.x << " , l : " << step0.l;
          cout <<" step1 - y : " << step1.y << " , x : " << step1.x << " , l : " << step1.l;

          dfs(pc, 0);
     }
}
