#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num[10]={0};
    string s;
    char str[1000000];
    int max=0;

    cin >> str;
    s=str;
    int l= s.size();
    for(int i=0; i<l; i++)
    {
        int x=str[i]-'0';
        num[x]++;
    }
    num[6]=(num[6]+num[9]+1)/2;
    for(int i=0; i<9; i++)
      if(max<num[i]) max=num[i];

        cout << max;
}
