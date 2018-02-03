//https://www.acmicpc.net/problem/5555
#include <iostream>
#include <string>
using namespace std;
char cmp[10];
int main()
{
     string origin;
     cin >> origin;
     int l=origin.size();

     int n,cnt;
     cin >> n;
     cnt=0;
     bool chk;
     for(int i=0 ; i<n; i++)
     {
          cin >> cmp;
          chk=0;
          for(int j=0 ;j <10; j++)
          {
               if(cmp[j]==origin[0]);
               {
                    for(int k=1; k<l; k++)
                    {
                         int x=(j+k)%10;
                         if(cmp[x]!=origin[k]) break;

                         if(k==l-1) { cnt++; chk=1; }
                    }
                    if(chk) break;
               }
          }
     }
     cout << cnt;
}
