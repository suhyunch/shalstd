//https://www.acmicpc.net/problem/5585
#include <iostream>
using namespace std;

int main()
{
     int n,rest;
     int cnt=0;
     cin >> n;

     rest=1000-n;

     cnt+=rest/500;
     rest%=500;

     cnt+=rest/100;
     rest%=100;

     cnt+=rest/50;
     rest%=50;

     cnt+=rest/10;
     rest%=10;

     cnt+=rest/5;
     rest%=5;

     cnt+=rest;

     cout << cnt;
}
