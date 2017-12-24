//https://www.acmicpc.net/problem/1162
#include <iostream>
using namespace std;
int map[10001][10001];
int main()
{
  int N, M, K;
  cin >> N >> M >> K;

  for(int i=0; i<M; i++)
  {
    int a,b;
    cin >> a >> b;
    cin>> map[a][b];
    map[b][a]=map[a][b];
  }

}
