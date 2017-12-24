//https://www.acmicpc.net/problem/5543
#include <iostream>
using namespace std;

int main()
{
     int hbg=2100;
     int bvrg=2100;

     for(int i=0;i<3; i++)
     {
          int x;
          cin >> x;

          if(hbg>x) hbg=x;
     }

     for(int i=0; i<2; i++)
     {
          int y;
          cin >> y;

          if(bvrg>y) bvrg=y;
     }
     cout << hbg << " " << bvrg << endl;
     cout << hbg+bvrg-50;
}
