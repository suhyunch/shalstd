//https://www.acmicpc.net/problem/2908
#include <iostream>
using namespace std;

int main()
{
  int a,b;
  cin >> a >> b;

  a= 100*(a%10) + 10*((a/10)%10) + (a/100);
  b= 100*(b%10) + 10*((b/10)%10) + (b/100);

  if(a>b) cout << a;
  else cout << b;
}
