//https://www.acmicpc.net/problem/11047
#include <iostream>
using namespace std;
int money[10];
 int main()
 {
      int n,K,ans;
      cin >> n >> K;

      for(int i=0; i<n; i++) cin >> money[i];
      ans=0;
      for(int i=n-1; i>=0; i--)
      {
           if((K/money[i]) >0) ans+=K/money[i];
           K%=money[i];
      }
      cout << ans;
}
