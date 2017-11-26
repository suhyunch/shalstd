//https://www.acmicpc.net/problem/1032
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  string str1, str2;
  int N;
  cin >> N >> str1;
  int l=str1.size();
  bool chk[51]={1,};
  if(N==1) {cout << str1; return 0;}
  for(int i=1; i<N; i++)
  {
    cin >> str2;
    for(int j=0; j<=l; j++)
      if(str1[j]!=str2[j])   chk[j]=0;
    str1=str2;
  }

  for(int i=0; i<l; i++)
  {
    if(chk[i]==1) cout<< str1[i];
    else cout << "?";
  }
}
