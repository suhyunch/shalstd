//https://www.acmicpc.net/problem/3460
#include <iostream>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t-->0){
          int n;
          cin >> n;

          for(int i=0; ;i++){
               if(n%2) cout <<i <<" ";
               n/=2;
               if(n==0) break;
          }
          cout << endl;
     }
     return 0;
}
