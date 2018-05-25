//https://www.acmicpc.net/problem/10815
#include <iostream>
#include <stdio.h>
using namespace std;

bool arr[20000005];
int main(){
     int n;
     scanf("%d", &n);
     for(int i=0; i<n; i++){
          int x;
          scanf("%d", &x);
          arr[x+10000000]++;
     }

     int m;
     scanf("%d", &m);


     while(m-->0){
          int x;
          scanf("%d", &x);
          printf("%d ", arr[x+10000000]);
     }
     putchar('\n');
     return 0;
}
