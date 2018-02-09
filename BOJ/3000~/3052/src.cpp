//https://www.acmicpc.net/problem/3052
#include <iostream>
using namespace std;
int num[1001];
int main(){
     int mx=0;
     int ans=0;
     for(int i=0; i<10; i++){
          int A;
          cin >> A;

          num[A%42]++;
          if(A>mx) mx=A;
     }

     for(int i=0; i<=mx; i++)
     {
          if(num[i]>0) ans++;
     }

     cout << ans;
}
