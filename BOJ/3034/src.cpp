//https://www.acmicpc.net/problem/3034
#include <iostream>
#include <math.h>
using namespace std;

 int main()
 {
      int n, w, h;
      cin >> n >> w >> h;

      for(int i=0; i<n; i++)
      {
           int x;
           cin >> x;

           if(x*x<=(w*w+h*h))
               cout << "DA"<<endl;
               else cout << "NE" << endl;
      }
}
