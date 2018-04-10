//https://www.acmicpc.net/problem/10818
#include <iostream>
using namespace std;

int main(){
     int N;
     cin >> N;
     int mx=-1000001, mn=1000001;

     int x;

     while(N-->0){
          cin >>x;
          if(x>mx) mx=x;
          if(x<mn) mn=x;
     }

     cout << mn << " " << mx;
     return 0;
}
