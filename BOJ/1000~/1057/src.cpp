//https://www.acmicpc.net/problem/1057
#include <iostream>
using namespace std;
int N, A, B;

int main(){
     cin >> N >> A >> B;

     int ans=1;
     while(1){
          if((!(A%2) && B==A-1) ||(!(B%2) && A==B-1)) break;
          else {
               if(A%2) A=(A+1)/2;
               else A=A/2;

               if(B%2) B=(B+1)/2;
               else B=B/2;
          }
          ans++;
     }

     cout << ans;
}
