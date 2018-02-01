//https://www.acmicpc.net/problem/1037
#include <iostream>
#include <algorithm>
using namespace std;
int num[51];

int main(){
      int A,N;
      cin >> N;
      int a,b,bin;

      if(N==1){
           cin >> a;
           cout << a*a;
           return 0;
      }

      for(int i=0; i<N; i++){
           cin >> num[i];
      }
      sort(num,num+N);

      cout << num[0]*num[N-1];
}
