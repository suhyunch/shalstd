//https://www.acmicpc.net/problem/1236
#include <iostream>
#include <string>
using namespace std;

int main(){
     bool chk[50][2]={0,};
     int n, m;
     cin >> n >> m;

     for(int i=0; i<n; ++i){
         string s;
         cin >> s;
          for(int j=0; j<m; ++j){
               if(s[j]=='X'){
                    chk[i][0]= true;
                    chk[j][1]= true;
               }
          }
     }

     int r=0;
     int c=0;

     for(int i=0; i<n; ++i)
          if(chk[i][0]==false)
               r++;
     for(int i=0; i<m; ++i)
          if(chk[i][1]==false)
               c++;

     if(r>c) cout << r;
     else cout <<c;

     return 0;
}
