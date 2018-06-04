//https://www.acmicpc.net/problem/10769
#include <iostream>
using namespace std;

int main(){
     char str[256];
     cin.getline(str, 255);
     int cnt[2]={0,0};
     for(int i=0; str[i]!=0; i++){
          if(str[i]==':' && (str[i+1]!=0 && str[i+2]!=0)){
               if(str[i+1]=='-'){
                    if(str[i+2]==')') cnt[0]++;
                    else if(str[i+2]=='(') cnt[1]++;
               }
          }
     }

     if(cnt[1]==0 && cnt[0]==0) cout <<"none";
     else if(cnt[0]==cnt[1]) cout <<"unsure";
     else if(cnt[0]>cnt[1]) cout <<"happy";
     else cout <<"sad";

     return 0;
}
