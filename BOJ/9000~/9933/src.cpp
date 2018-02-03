//https://www.acmicpc.net/problem/9933
#include <iostream>
#include <string>
using namespace std;

int main()
{
     int n;
     cin >> n;
     char word[101][14];
     for(int i=0; i<n; i++)
          cin >> word[i];

     for(int i=0;i<n; i++)
     {
          string s1;
          s1=word[i];
          for(int j=i; j<n;j++)
          {
               string s2;
               s2=word[j];

               int l1=s1.size();
               int l2=s2.size();

               if(l1 != l2) continue;
               for(int k=0; k<l1; k++)
               {
                    if(s1[k] != s2[l1-k-1]) break;
                    if(k==l1-1) { cout << l1 <<" " << s1[l1/2]; return 0;}
               }
          }
     }
}
