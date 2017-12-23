//https://www.acmicpc.net/problem/1547
#include <iostream>
using namespace std;

int main()
{
     int m;
     bool cup[4]={0,1,0,0};
     cin >> m;

     for(int i=0 ;i<m; i++)
     {
          int x,y;

          cin >> x >> y;

          int tmp=cup[x];
          cup[x]=cup[y];
          cup[y]=tmp;
     }
     for(int i=1; i<=3; i++)
          if(cup[i]) cout << i << endl;
}
