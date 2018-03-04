//https://www.acmicpc.net/problem/1212
#include <iostream>
using namespace std;

int main(){

     char ett1[8][4]={"000","001","010","011","100","101","110","111"};
     char ett2[8][4]={"0","1","10","11","100","101","110","111"};
     string octo;
     cin >> octo;

     int ls=octo.size();
     for(int i=0; i<ls; i++){
          int y=octo[i]-'0';
          if(i==0){
               cout << ett2[y];
          }
          else cout << ett1[y];
     }

     return 0;
}
