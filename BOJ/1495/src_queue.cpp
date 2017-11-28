//https://www.acmicpc.net/problem/1495
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int max(int a, int b) {return a> b? a:b;}

int V[101];

int main()
{
  int N, S, M;
  cin >> N >> S >> M;
  int x, y;
  for(int i=1; i<=N; i++) cin >> V[i];

  queue<int> q;

  q.push(S);
  for(int i=1; i<=N; i++)
  {
    int x=pow(2,i-1);
    int y=0;
    for(int j=1; j<=x; j++)
    {
      int now=q.front();
      q.pop();
      if(now < 0 || now >M) continue;

      q.push(now-V[i]);
      q.push(now+V[i]);
      if(q.empty()) {cout << "-1"; return 0;}
    }
  }

  int k=q.size();
  int c=0;
  int max=q.front();
  q.pop();
  while(!q.empty())
  {
    int b=q.front();
    if(b<0||b>M) c++;
    if(max<b && b>=0 && b <=M)
      max=b;
    q.pop();
  }
  if(c==k) cout << "-1";
  else cout << max;
}
