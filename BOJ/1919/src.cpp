//https://www.acmicpc.net/problem/1919
#include <iostream>
#include <string>
using namespace std;

int main()
{
     string s1, s2;
     cin >> s1 >> s2;

     int l1=s1.size();
     int l2=s2.size();
     int cnt=0;

     for(int i=0; i<l1; i++)
          for(int j=0; j<l2; j++)
               if(s1[i]==s2[j])
               {cout << s1[i] << "  " << s2[j] << endl;
                    s1[i]='.';
                    s2[i]='.';
                    break;
               }


for(int i=0; i<l1; i++) cout << s1[i] ;
cout << endl;
for(int i=0; i<l2; i++) cout << s2[i] ;
cout << endl;
     for(int i=0; i<l1; i++)
          if(s1[i]=='.') continue;
          else cnt++;

     for(int i=0; i<l2; i++)
          if(s2[i]=='.') continue;
          else cnt++;

          cout << cnt;
}
