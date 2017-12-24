//https://www.acmicpc.net/problem/5565
#include <iostream>
using namespace std;

int main()
{
     int total, now;

     cin >> total;

     for(int i=0; i<9; i++)
     {
          cin >> now;

          total-=now;
     }

     cout << total;
}
