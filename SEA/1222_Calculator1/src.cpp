#include <iostream>
#include <string>
using namespace std;

int main()
{
  for(int tc=1; tc<=10; tc++)
  {
    int x;
    int sum=0;
    string str;
    cin >> x >> str;

    for(int i=0; i<x; i++)
    {
      if(!(i%2)) sum+=str[i]-'0';
    }
    cout << "#" << tc << " "<< sum <<endl;
  }
}
