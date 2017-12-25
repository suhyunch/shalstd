//https://www.acmicpc.net/problem/2998
#include <iostream>
#include <string>
using namespace std;

  int main()
  {
       string bin;
       cin >> bin;

       int l=bin.size();
       int x;

       if(l%3==0)// 3개로 나누어 떨어짐
       {
            for(int i=0; i<l; i+=3)
            {
                 x=(bin[i]-'0')*4+(bin[i+1]-'0')*2+(bin[i+2]-'0');
                 if(x==0) cout << "0";
                 else if(x==1) cout << "1";
                 else if(x==2) cout << "2";
                 else if(x==3) cout << "3";
                 else if(x==4) cout << "4";
                 else if(x==5) cout << "5";
                 else if(x==6) cout << "6";
                 else cout << "7";
            }
       }

       else if(l%3==1)
       {
            cout << "1";
            for(int i=1; i<l; i+=3)
            {
                 x=(bin[i]-'0')*4+(bin[i+1]-'0')*2+(bin[i+2]-'0');
                 if(x==0) cout << "0";
                 else if(x==1) cout << "1";
                 else if(x==2) cout << "2";
                 else if(x==3) cout << "3";
                 else if(x==4) cout << "4";
                 else if(x==5) cout << "5";
                 else if(x==6) cout << "6";
                 else cout << "7";
            }
       }

       else if(l%3==2)
       {
            if((bin[1]-'0')==0) cout << "2";
            else cout << "3";
            for(int i=2; i<l; i+=3)
            {
                 x=(bin[i]-'0')*4+(bin[i+1]-'0')*2+(bin[i+2]-'0');
                 if(x==0) cout << "0";
                 else if(x==1) cout << "1";
                 else if(x==2) cout << "2";
                 else if(x==3) cout << "3";
                 else if(x==4) cout << "4";
                 else if(x==5) cout << "5";
                 else if(x==6) cout << "6";
                 else cout << "7";
            }
       }
 }
