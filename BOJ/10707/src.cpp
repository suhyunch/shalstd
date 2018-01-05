//https://www.acmicpc.net/problem/10707
#include <iostream>
using namespace std;

int main()
{
     int a,b,c,d,p;
     cin >>a >> b >> c>> d>> p;

     int costx=a*p;
     int costy=(p>c ?b+d*(p-c) :b );

     if(costx>costy) cout << costy;
     else cout << costx;
}
