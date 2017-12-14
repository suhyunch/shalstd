//https://www.acmicpc.net/problem/1110
#include <iostream>
using namespace std;

int main()
{
     int origin, x, n;

     cin >> origin;
     x=origin;
     for(n=1; ;n++)
     {
          int a=x%10;
          x = x/10 + x%10;
          x = a*10+x%10;
          if(x==origin) break;
     }

     cout << n;
}
