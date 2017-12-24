//https://www.acmicpc.net/problem/1789
#include <iostream>
using namespace std;

int main()
{
     long long S;
     cin >> S;

     int i=0;
     while(1)
     {
          i++;
          S-=i;
          if(S<=i) break;
     }

     cout << i;
}
