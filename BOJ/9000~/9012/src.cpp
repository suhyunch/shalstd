//https://www.acmicpc.net/problem/9012
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool vps(){
     stack<char> s;
     string str;
     cin >>str;
     int l=str.size();
     s.push(str[0]);
     for(int i=1; i<l; i++){
          if(str[i]==')'){
               if(!s.empty()){
                    if(s.top()=='(')
                         s.pop();
               }
               else s.push(str[i]);
          }
          else s.push(str[i]);
     }
     if(s.empty()) return true;
     else return false;
}
int main(){
     int tc;
     cin >> tc;
     for(int i=0; i<tc; i++){
          if(vps()) cout << "YES\n";
          else cout <<"NO\n";
     }
     return 0;
}
