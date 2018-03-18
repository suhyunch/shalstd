//https://www.acmicpc.net/problem/1182
#include <iostream>
using namespace std;
int arr[20];
int cnt;
int N, S;
void match(int idx, int sum){
     if(idx==N){
          cnt = sum==S ? cnt+1 : cnt;
          return;
     }

     for(int i=0; i<2; i++){
          match(idx+1,sum = i==true? sum+arr[idx] : sum);
     }
}
int main(){

     cin >> N >> S;

     for(int i=0; i<N; i++){
          cin >> arr[i];
     }

     match(0, 0);
     if(S==0) cnt--;
     cout << cnt;
}
