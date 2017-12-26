//https://www.acmicpc.net/problem/2563
#include <iostream>
using namespace std;
bool paper[100][100];

int main()
{
     int n,ans,x,y;
     cin >> n;

     ans=0;
     for(int i=0 ; i<n; i++)
     {
          cin >> x >> y;

          for(int j=0; j<10; j++)
               for(int k=0; k<10; k++)
               {
                    if(!paper[y+j][x+k]) ans++;
                    else continue;
                    paper[y+j][x+k]=1;
               }
     }

     cout << ans;
}
