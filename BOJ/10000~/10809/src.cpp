//10809 알파벳 찾기 https://www.acmicpc.net/problem/10809
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int alphabet[26];
  for(int i=0; i<26; i++) alphabet[i]=-1;
  string s;
  cin >> s;
  int l=s.size();

  for(int i=0; i<l; i++)
  {
    if(alphabet[s[i]-'a']==-1) alphabet[s[i]-'a']=i;
  }


  for(int i=0; i<26; i++) cout << alphabet[i] << " ";
}
