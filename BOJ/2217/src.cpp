//https://www.acmicpc.net/problem/2217
#include <iostream>
#include <algorithm>
using namespace std;

 int main()
 {
      int n,tmp;
      int rope[100001];
      int ans=0;

      cin >> n;

      for(int i=1; i<=n; i++)
          cin >> rope[i];

     sort(rope+1, rope+n+1);

     for(int i=1; i<=n; i++)
     {
          tmp=(n-i+1)*rope[i];
          if(ans<tmp) ans=tmp;
     }

     cout << ans;
}
