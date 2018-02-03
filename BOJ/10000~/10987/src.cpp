//https://www.acmicpc.net/problem/10987
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;

  cin >> s;

  int l=s.size();
  int cnt=0;
  for(int i=0; i<l; i++)
  {
    if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' )
    cnt++;
  }
  cout << cnt;
}
