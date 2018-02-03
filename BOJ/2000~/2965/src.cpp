//https://www.acmicpc.net/problem/2965
#include <iostream>
using namespace std;
int map[3];
int minind, maxind;
int diff(int a, b) {return a >b ? a-b: b-a;}
void ind()
{
     int resultmin, resultmax;
     if(map[0]>map[1])
     {
          resultmin=1; resultmax=0;
          if(map[2]<map[resultmin])
          {
               resultmin=2;

          }
          if(map[2]>map[resultmax]) resultmax=2;
     }
     else
     { 
          resultmin=0; resultmax=1;
          if(map[2]<map[resultmin]) resultmin=2;
          if(map[2]>map[resultmax]) resultmax=2;
     }
}
int main()
{
     int a,b,c,cnt;

     cin >> a >> b >>c;

     map[0]=a;
     map[1]=b;
     map[2]=c;

     cnt=0;
     while(map[0]!=map[1] && map[1]!=map[2] && map[2]!=map[0])
     {
          cnt++;
          ind();

     }
}
