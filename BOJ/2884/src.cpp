//https://www.acmicpc.net/problem/2884
#include <iostream>
using namespace std;

 int main()
 {
      int h,m;
      cin >> h >> m;

      if(m<45) {
           if(h==0) h=24;
          else h--;
           m=15+m;
      }
      else m-=45;

      cout << h << " " << m;
}
