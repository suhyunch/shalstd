//https://www.acmicpc.net/problem/1159
#include <iostream>
using namespace std;
int cntalphb[26];

 int main()
 {
      int n;
      cin >> n;
      bool chk=0;
      for(int i=0; i<n; i++)
      {
           char name[30];
           cin >> name;

           cntalphb[name[0]-'a']++;
      }

      for(int i=0; i<26; i++)
      {
           if(cntalphb[i]>=5)
           {
                chk=1;
                cout << (char)(i+'a');
           }
      }

      if(!chk) cout << "PREDAJA";
}
