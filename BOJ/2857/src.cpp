//https://www.acmicpc.net/problem/2857
#include <iostream>
#include <string>
using namespace std;

int main()
{
     int cnt=0;
     for(int i=1; i<=5; i++)
     {
          string s;
          cin>> s;
          int l=s.size();

          for(int j=0; j<l-2; j++)
               if(s[j]=='F' && s[j+1]=='B' && s[j+2]=='I')
               {
                    cnt++;
                    cout << i <<" ";
                    break;
               }
     }

     if(!cnt) cout << "HE GOT AWAY!";
}
