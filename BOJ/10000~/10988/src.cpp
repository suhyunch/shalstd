//https://www.acmicpc.net/problem/10988
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
     string s;
     cin >> s;
     bool chk=0;
     int l=s.size();
     for(int i=0; i<l/2; i++)
          if(s[i]!=s[l-1-i]) {chk=1; break;}
     if(chk) cout << "0";
     else cout << "1";
}
