//https://www.acmicpc.net/problem/5598
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int l=s.size();

  for(int i=0;i<l; i++)
  {
    if(s[i]-'A'<3) cout << (char)(s[i]+23);
    else cout << (char)(s[i]-3);
  }
}
