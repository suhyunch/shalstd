//https://www.acmicpc.net/problem/2161
#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
queue<int> card;
int main(){
     int N;

     cin >> N;
     for(int i=1; i<=N; i++) card.push(i);

     while(!card.empty()){
          q.push(card.front());
          card.pop();
          card.push(card.front());
          card.pop();
     }

     for(int i=0; i<N; i++){
          cout <<q.front() <<" ";
          q.pop();
     }
     return 0;
}
