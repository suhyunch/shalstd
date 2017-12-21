//https://www.acmicpc.net/problem/2010
#include <iostream>
using namespace std;

int main()
{
     int n;
     cin >> n;

     int sum=0;
     for(int i=0; i<n; i++)
     {
          int x;
          cin >> x;
          sum+=x;
     }

     cout << sum-n+1 ;
}
