#include <iostream>
using namespace std;
int use[13];
int cost[4];
int mn;
void input();
void solve(int depth, int tcost);

int main(){
     int tc;
     scanf("%d", &tc);

     for(int T=1; T<=tc; T++){
          input();
          mn=cost[3];

          cost[0]*use[1]<cost[1] ? solve(1, cost[0]*use[1]) : solve(1, cost[1]);
          solve(3, cost[2]);

          printf("#%d %d\n", T, mn);
     }
     return 0;
}


void input(){
     for(int i=0; i<4; i++) scanf("%d", cost+i );
     for(int i=1; i<13; i++){
          scanf("%d", use+i );
     }
}

void solve(int depth, int tcost){
     if(depth>12){
          if(mn>tcost) mn=tcost;
          return;
     }
     tcost+cost[0]*use[depth+1]<tcost+cost[1] ? solve(depth+1, tcost+cost[0]*use[depth+1]) : solve(depth+1, tcost+cost[1]);
     solve(depth+3, tcost+cost[2]);
}
