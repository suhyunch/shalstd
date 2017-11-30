//https://www.acmicpc.net/problem/1316
#include <iostream>
#include <string>
using namespace std;

int main()
{
  int N;
  cin >> N;
  int cnt=0;

  for(int i=0; i<N; i++)
  {
    string word;
    cin >> word;
    bool alphbet[26]={0};
    bool chk=0;
    int l=word.size();
    for(int j=0; j<l; j++)
    {
      if(j>0 && word[j]!=word[j-1] && alphbet[word[j]-'a']) chk=1;
      alphbet[word[j]-'a']=1;
    }
    if(!chk) cnt++;
  }
  cout << cnt;
}
