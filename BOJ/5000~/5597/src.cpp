//https://www.acmicpc.net/problem/5597
#include <iostream>
using namespace std;

int max(int a, int b) {
     return a>b ? a : b;
}
int min(int a, int b) {
     return a<b ? a : b;
}
bool chk[31];
int main(){
     for(int i=0; i<28; i++) {
          int x;
          cin >> x;
          chk[x]=1;
     }
     int ans1=0, ans2=0;

     for(int i=1; i<=30; i++){
          if(chk[i]==0){
               if(ans1==0) ans1=i;
               else {
                    ans2=i;
                    break;
               }
          }
     }

     cout << max(ans1, ans2) << '\n'<< min(ans1, ans2);
     return 0;
}
