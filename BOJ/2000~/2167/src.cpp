//https://www.acmicpc.net/problem/2167
#include <iostream>
using namespace std;
int arr[301][301];

int main()
{
     int n, m, k, dp;
     cin >> n >> m;

     for(int i=1; i<=n; i++)
          for(int j=1; j<=m; j++)
               cin >> arr[i][j];

     cin >> k;
     for(int a=0; a<k; a++)
     {
          int i, j,x,y;
          cin >> i >> j >> x >> y;

          int sum=0;
          for(int b=i; b<=x; b++)
          {
               for(int c=j; c<=y; c++)
                    sum+=arr[b][c];
          }
          cout << sum << endl;
     }
}
