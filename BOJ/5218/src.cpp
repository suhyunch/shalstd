//https://www.acmicpc.net/problem/5218
#include <iostream>
#include <string>
using namespace std;

int main()
{
     int N;
     cin >> N;

     for(int i=0; i<N; i++)
     {
          string s1,s2;
          cin >> s1 >> s2;

          cout << "Distances: " ;
          int l=s1.size();
          for(int j=0;j<l; j++)
          {
               if((int)s1[j]>(int)s2[j]) cout << s2[j]-s1[j] +26  << "  ";
               else cout << s2[j]-s1[j] << " ";
          }
          cout << endl;
     }
}
