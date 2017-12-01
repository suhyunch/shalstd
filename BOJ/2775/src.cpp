//https://www.acmicpc.net/problem/2775
#include <iostream>
using namespace std;

int apart[15][15];

int main()
{
  int T;
  cin >> T;

  for(int i=1; i<15; i++)
  { apart[0][i]=i;  }
  for(int tc=0; tc<T; tc++)
  {
    int k, n;
    cin >> k >> n;
    for(int a=1; a<=k; a++)
    {
      apart[a][1]=apart[a-1][1];
      for(int b=2; b<=n; b++)
        apart[a][b]=apart[a-1][b]+apart[a][b-1];
    }

    cout << apart[k][n] << endl;
  }
}
