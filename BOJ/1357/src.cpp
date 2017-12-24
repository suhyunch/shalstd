//https://www.acmicpc.net/problem/1357
#include <iostream>
using namespace std;
int rev(int n)
{
     int revn=0;
     while(n>0)
     {
          revn*=10;
          revn+=n%10;
          n/=10;
     }
     return revn;
}
int main()
{
     int x,y;
     cin >> x >> y;

     cout<< rev(rev(x)+rev(y));
}
