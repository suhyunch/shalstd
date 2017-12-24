//https://www.acmicpc.net/problem/10797
#include <iostream>
using namespace std;

int main()
{
     int day,x;
     cin >> day;
     int cnt=0;

     for(int i=0; i<5; i++)
     {
          cin >>x;
          if(day==x) cnt++;
     }
     cout << cnt;
}
