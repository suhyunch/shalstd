//https://www.acmicpc.net/problem/3613
#include <iostream>
#include <string>
using namespace std;
int main()
{
     string s;
     bool chk_=0;
     bool chkB=0;
     bool javaorcpp=0;
     cin >> s;
     int l=s.size();

     string javaidtf="javaIdentifier";
     string cidtf="c_identifier";

     if(s.compare(javaidtf)==0)
     { cout <<"c_identifier"; return 0;}
     else if((s.compare(cidtf)==0) )
     { cout << "javaIdentifier"; return 0;}


     if((int)s[0]<=90) {cout <<  "Error!"; return 0;}
     if(s[l-1]=='_') {cout <<  "Error!"; return 0;}
     for(int i=0; i<l; i++)
     {
          if((int)s[i]<=90) chkB=1;
          if(s[i]=='_')
          {
               chk_=1;
               if(i!=0 && s[i-1]=='_') {cout <<  "Error!"; return 0;}
          }
     }

     if(chkB && chk_) {cout <<  "Error!"; return 0;}
     else if(chkB && !chk_) javaorcpp=0; //java
     else if(!chkB && chk_) javaorcpp=1; // cpp

     if(javaorcpp)//cpp
     {
          int starter=1;
          if(s[0]=='_') { starter=2; cout << (char)(s[1]-'a'+'A');}
          else cout << s[0];
          for(int i=starter; i<l; i++)
          {
               if(s[i]=='_') continue;
               if(s[i-1]=='_') cout << (char)(s[i]-'a'+'A');
               else cout << s[i];
          }
     }

     else
     {
          cout << s[0];
          for(int i=1; i<l; i++)
          {
               if((int)s[i]<=90) cout << "_" << (char)(s[i]-'A'+'a');
               else cout << (char)s[i];
          }
     }
}
