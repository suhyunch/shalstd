//https://www.acmicpc.net/problem/13458
#include <iostream>
using namespace std;

int N, B, C;

int A[1000000];
int main(){
     cin >> N;


     for(int i=0; i<N; i++)
          cin >> A[i];

     cin >> B >> C;
     long long ans=N;//감독관 무조건 1명
     for(int i=0; i<N; i++){
          if(A[i]<B) continue;
          else{
               ans+=(A[i]-B+C-1)/C;
          }
     }
     cout << ans;
}
