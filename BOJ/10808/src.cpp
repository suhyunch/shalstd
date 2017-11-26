//https://www.acmicpc.net/problem/10808
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int alphabet[26];
  for(int i=0; i<26; i++) alphabet[i]=0;
  string s;
  cin >> s;
  int l=s.size();

  for(int i=0; i<l; i++)
  alphabet[s[i]-'a']++;


  for(int i=0; i<26; i++) cout << alphabet[i] << " ";
}
