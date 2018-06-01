//https://www.acmicpc.net/problem/1934
#include <iostream>
using namespace std;

int gcd(int a, int b){
     return b? gcd(b, a%b) : a;
}
int main(){
    int t;
    cin>>t;
    while(t-->0){
    int a, b;

     cin >> a >> b;
     if(a<b) {
          int tmp=a;
          a=b;
          b=tmp;
     }
     int ans=gcd(a,b);
     cout << a*b/ans <<endl;
    }
     return 0;
}
