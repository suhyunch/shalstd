#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l=s.size();
    int alphabet[26]={0};
    int max=0;
    int max_index;
    int cnt=0;
    for(int i=0; i<l; i++)
    {
       int x;
        if ((int)s[i]-'A'>26) x=s[i]-'a';
        else  x=s[i]-'A';
        alphabet[x]++;

        if(max<alphabet[x])
        {
          max=alphabet[x];
          max_index=x;
        }
      }
      
      for(int i=0; i<26; i++)
      { if(max==alphabet[i])
          if(cnt ==1) {cout << "?" ; return 0; }
          else cnt++;
        }

      cout << (char)(max_index+'A');
}
