//https://www.acmicpc.net/problem/4597
#include <iostream>
#include <string>
using namespace std;

int main(){
     while(true){
          string s;
          cin>>s;
          if(s[0]=='#') return 0;

          int l=s.size();
          int one=0;
          bool mode=0;
          for(int i=0; i<l; i++){
               if(i==l-1){
                    if(s[i]=='e') mode=1;
                    break;
               }
               else{
                    if(s[i]=='1') one++;
               }
          }
          for(int i=0; i<l-1; i++)cout <<s[i];
          if(!mode){
               if(one%2)
                    cout <<"0\n";
               else
                    cout << "1\n";
          }
          else{
               if(one%2)
                    cout <<"1\n";
               else
                    cout << "0\n";
          }
     }
     return 0;
}
