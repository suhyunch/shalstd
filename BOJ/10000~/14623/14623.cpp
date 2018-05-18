//https://www.acmicpc.net/problem/14623
#include <iostream>
#include <string>
using namespace std;

int main(){
     string b1,b2;
     cin >> b1 >> b2;

     int l1=b1.size();
     int l2=b2.size();
     int ans[64]={0,};
     int digit=1;
     int length;
     for(int i=l2-1; i>=0; --i){
          int idx=1*digit;
          for(int j=l1-1; j>=0; --j){
               ans[idx++]+=(b1[j]-'0')*(b2[i]-'0');
          }
          ++digit;
          length=idx;
     }

     for(int i=1; i<length; i++){
          if(ans[i]>=2){
               ans[i+1]+=(ans[i]/2);
               ans[i]%=2;
          }
     }

     for(int i=length; i>0; i--) {
          if(i==length && ans[i]==0) continue;
          cout << ans[i];
     }
     return 0;
}
