//https://www.acmicpc.net/problem/1476
#include <iostream>
using namespace std;

int main()
{
  int E, S, M;
  cin >> E >> S >> M;

  E%=15;
  S%=28;
  M%=19;
  for(int i=1; ;i++)
    if((i%15)==E && (i%28)==S && (i%19)==M)
    {
      cout << i ;
      break;
    }
}
