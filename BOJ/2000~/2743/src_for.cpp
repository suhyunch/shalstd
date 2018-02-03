//https://www.acmicpc.net/problem/2743
#include <iostream>
using namespace std;

int main()
{
  char str[101];
 cin >> str;

  for(int i=0 ;i<101; i++)
  {
    if(str[i]==NULL) {cout << i; return 0;}
  }
}
