//https://www.acmicpc.net/problem/10886
#include <iostream>
using namespace std;

int main()
{
     bool x;
     int N;
     cin  >> N;

     int cnt=0;
     for(int i=0; i<N; i++)
     {
          cin >> x;
          if(x) cnt++;
          else //x==0
               cnt--;
     }

     if(cnt>0) cout <<  "Junhee is cute!";
     else cout << "Junhee is not cute!";
}
