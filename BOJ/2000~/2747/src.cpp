//https://www.acmicpc.net/problem/2747
#include <iostream>
using namespace std;

void memoization(int f[]);
int search(int f[], int n);
int main(){
     int f[45];
     memoization(f);
     int n;
     cin >> n;
     cout << search(f, n);
     return 0;
}

void memoization(int f[]){
     f[0]=0;
     f[1]=1;
     for(int i=2; i<=45; i++){
          f[i]=f[i-1]+f[i-2];
     }
     return;
}

int search(int f[], int n){
     return f[n];
}
