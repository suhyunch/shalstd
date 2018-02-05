//https://www.acmicpc.net/problem/5014
#include <iostream>
#include <queue>
using namespace std;
int BD[1000001];
int F,S,G,U,D;
int mn=10000003;

bool bfs(){
     queue<int> q;
     q.push(S);

     BD[S]=1;

     while(!q.empty()){
          int now=q.front();
          q.pop();

          if(now==G){
               if(mn>BD[now]) mn=BD[now];
               return true;
          }

          int nu=now+U;
          int nd=now-D;

          if(nu>0 && nu<=F && !BD[nu]){
               q.push(nu);
               BD[nu]=BD[now]+1;
          }

          if(nd>0 && nd<=F && !BD[nd]){
               q.push(nd);
               BD[nd]=BD[now]+1;
          }

     }

     return false;
}



int main(){
     cin >> F >> S >> G >> U >> D;

     if(bfs()) cout << mn-1;
     else cout << "use the stairs";

     return 0;
}
