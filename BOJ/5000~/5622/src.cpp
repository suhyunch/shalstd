//https://www.acmicpc.net/problem/5622
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string num;
  cin >> num;
  int x;
  int l=num.size();
  int sum=0;
  for(int i=0; i<l; i++)
  {
    if(num[i]=='1') x=2;
    else if(num[i]=='Z' ) x= 10;
    else if((int)num[i]>='S')  x= (num[i]-'A'-1)/3+3;
    else x= (num[i]-'A')/3+3;
    sum+=x;
  }
  cout << sum;
}
