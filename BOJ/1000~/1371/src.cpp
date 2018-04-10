//https://www.acmicpc.net/problem/1371
#include <iostream>
#include <string>
using namespace std;
int cnt[26];
int mx=0;
int idx;
bool chk=0;
int main(){
     char now;
     for(int i=0; i<5001; i++){
          cin>> now;
          if(now == 0 || now ==' ') continue;
          cnt[now-'a']++;
     }


     for(int i=0; i<26; i++){
          if(cnt[i]>mx) {
               mx=cnt[i];
               idx=i;
          }
     }

     cout << (char)(idx+'a') << endl;
}
