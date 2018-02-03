//https://www.acmicpc.net/problem/2875
#include <iostream>
using namespace std;

int main()
{
     int n,m,k;
     int female,male,cnt,max1;

     cin >> n >> m >> k;
     max1=0;
     for(int i=k; i>=0; i--)
     {
          if(n-i<0) break;
          female=n-i;
          male=m-(k-i);

          if(female>=2*male) cnt=male;
          else if(female<2*male) cnt=female/2;

          if(max1<cnt) max1=cnt;
     }
     cout << max1;
}
