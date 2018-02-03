//https://www.acmicpc.net/problem/14646
#include <iostream>
using namespace std;
bool menu[100001];

int main()
{
     int n,x;
     cin >> n;

     int cnt=0;
     int max=0;
     for(int i=0; i<2*n; i++)
     {
          cin >> x;
          if(menu[x]) cnt--;

          else
          {
               menu[x]=true;
               cnt++;
          }
          if(cnt>max) max=cnt;
     }

     cout << max;
}
