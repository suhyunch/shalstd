//https://www.acmicpc.net/problem/2660
#include <iostream>
#include <queue>
using namespace std;
bool frd[51][51];
bool visit[51];
int score[51];
int list[51];
int n;
int mn=51*51;
int num;

void input();
int bfs(int people);
void find();
void init();

int main(){
     input();

     for(int i=1; i<=n; i++){
          init();
          score[i]=bfs(i);
     }
     find();
}

void input(){
     cin >> n;
     int a=1, b=1;
     while(a!=-1 && b!=-1)
     {
          cin >> a >> b;
          frd[a][b]=frd[b][a]=1;

     }
}

int bfs(int people){
     queue<int> q;
     int tmp_cnt=1;
     int scr=-1;
     q.push(people);

     while(!q.empty()){
          scr++;
          int tmp=0;
          while(tmp_cnt-->0){
               int now=q.front();
               q.pop();
               visit[now]=1;

               for(int i=1; i<=n; i++){
                    if(frd[now][i] && !visit[i]){
                         q.push(i);
                         visit[i]=1;
                         tmp++;
                    }
               }
          }
          tmp_cnt=tmp;
     }
     if(mn>scr) {
          mn=scr;
          num=1;
     }
     else if(mn==scr) num++;
     return scr;
}

void find(){
     cout << mn<<" "<<num<<endl;
     for(int i=1; i<=n; i++){
          if(mn==score[i]) cout << i <<" ";
     }
}

void init(){
     for(int i=0; i<=n; i++) visit[i]=0;
}
