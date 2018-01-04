//https://www.acmicpc.net/problem/13116
#include <iostream>
#include <cstring>
using namespace std;
int a[11];
int b[11];

 int main()
 {
      int T, A, B;
      bool chk;
      cin >> T;
      for(int tc=0 ; tc<T; tc++)
      {
           cin >> A >> B;
           memset(a,0,11*sizeof(int));
           memset(b,0,11*sizeof(int));

           int j=0;
           for(int i=A; i>0; i/=2)
                a[j++]=i;

           j=0;
           for(int i=B; i>0; i/=2)
               b[j++]=i;

          chk=0;

          for(int i=0; i<11; i++)
          {
               for(int j=0; j<11; j++)
                    if(a[i]==b[j])
                    {
                         cout << a[i] << "0" <<endl;
                         chk=1;
                         break;
                    }
               if(chk) break;
          }
      }
}
