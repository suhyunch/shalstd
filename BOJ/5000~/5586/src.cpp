//https://www.acmicpc.net/problem/5586
#include <iostream>
#include <string>
using namespace std;

int main()
{
     string s;
     cin >> s;

     int l=s.size();
     int cntj=0;
     int cnti=0;
     for(int i=0; i<l-2; i++)
     {
          if(s[i]=='J' && s[i+1]=='O' && s[i+2]=='I') cntj++;
          else if(s[i]=='I' && s[i+1]=='O' && s[i+2]=='I') cnti++;
     }
     cout << cntj << endl << cnti;
}
