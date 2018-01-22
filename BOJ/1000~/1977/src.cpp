//https://www.acmicpc.net/problem/1977
#include <iostream>
using namespace std;

int main()
{
     int m,n, sum, min;
     cin >> m>> n;

     sum=0;
     min=0;
     for(int i=1; i<=100; i++)
     {
          if(i*i >=m)
          {
               if(min==0) min=i*i;
               for(int j=i; j*j<=n; j++)
               {
                    sum+=j*j;
               }

               break;
          }
     }

     if(sum==0) cout << -1;
     else cout << sum << endl << min;
}
