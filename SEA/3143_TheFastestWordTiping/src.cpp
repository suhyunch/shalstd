#include <iostream>
#include <string>
using namespace std;

int main()
{
     int T;
     cin >> T;
     for(int i=1; i<=T; i++)
     {
          string a, b;
          cin >> a>> b;

          int la=a.size();
          int lb=b.size();
          int cnt=0;
          for(int j=0; j<la; j++)
          {
               if(a[j]==b[0])
               {
                    for(int k=1; k<lb; k++)
                    {
                         if(a[j+k]!=b[k]) break;
                         if(k==lb-1) j+=lb-1;
                    }
               }
               cnt++;
          }

          cout << "#" << i <<" " << cnt << endl;
     }
}
