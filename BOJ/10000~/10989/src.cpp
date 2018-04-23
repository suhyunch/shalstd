//https://www.acmicpc.net/problem/10989
#include <iostream>
#include <stdio.h>
using namespace std;

int num[10001];
int main(){
     int n;
     scanf("%d",&n);
     int input;
     for(int i=0; i<n; ++i){
          scanf("%d",&input);
          num[input]++;
     }

     for(int i=1; i<=10000; ++i){
          while(num[i]-->0){
               printf("%d\n", i);
          }
     }
     return 0;
}
