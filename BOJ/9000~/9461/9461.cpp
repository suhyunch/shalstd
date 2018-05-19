//https://www.acmicpc.net/problem/9461
#include <iostream>
using namespace std;

long long int p[101];

int main(){
     p[1]=p[2]=p[3]=1;
     p[4]=p[5]=2;
     p[6]=3;
     p[7]=4;
     p[8]=5;
     p[9]=7;
     p[10]=9;
     for(int i=11; i<=100; i++){
          p[i]=p[i-1]+p[i-5];
     }
     int t;
     cin>> t;

     while(t-->0){
          int n;
          cin>>n;
          cout <<p[n]<<endl;
     }
     return 0;
}
