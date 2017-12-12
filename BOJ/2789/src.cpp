//https://www.acmicpc.net/problem/2789
#include <iostream>
#include <string>
using namespace std;

int main()
{
     string s;
     s="CAMBRIDGE";
     int l=s.size();

     string str;
     cin >> str;
     int l2=str.size();

     for(int i=0; i<l2; i++)
          for(int j=0; j<l; j++)
               if(str[i]==s[j])
                    str[i]='x';

     l2=str.size();
     for(int i=0 ; i<l2; i++)
     {
          if(str[i]=='x') continue;
          else cout << str[i];
     }
}
