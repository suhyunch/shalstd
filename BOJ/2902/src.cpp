//https://www.acmicpc.net/problem/2902
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;

  int l=s.size();
  cout << s[0];
  for(int i=0; i<l; i++)
  {
    if(s[i]=='-') cout << s[i+1];
  }
}
