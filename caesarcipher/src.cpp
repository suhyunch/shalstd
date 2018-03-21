#include <iostream>
#include <string>
using namespace std;

int main(){
     string s;
     cin >> s;
     int l=s.size();
     for(int i=1; i<27; i++){
               cout << i << " :: ";
               for(int j=0; j<l; j++){
                    if(s[j]+i>'z')cout << (char)(s[j]+i-'z'+'a'-1);
                    else cout << (char)(s[j]+i);
               }

               cout << endl;
     }
}
