//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>
using namespace std;
int time1[1000];

 int main()
 {
      int n,ans;
      cin >> n;

      for(int i=0; i<n; i++)
          cin >> time1[i];

     sort(time1, time1+n);

     ans=0;
     for(int i=0; i<n; i++)
          ans+=time1[i]*(n-i);

     cout << ans;
}
