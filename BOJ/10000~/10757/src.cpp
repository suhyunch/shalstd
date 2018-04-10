#include <iostream>
#include <string>
using namespace std;
char ans[10001];
int main(){
     string A;
     string B;
     cin >> A >> B;

     int a_l=A.length();
     int b_l=B.length();
     int idx_bigger=(a_l>b_l ? a_l : b_l)+1;
     int idx_a= a_l-1;
     int idx_b=b_l-1;
     int end=idx_bigger;
     int carry=0;

     while(idx_a>=0 && idx_b>=0){
          int a=A[idx_a--]-'0';
          int b=B[idx_b--]-'0';
          ans[idx_bigger--]=(char)((a+b+carry)%10+'0');
          if(a+b+carry>=10){
               carry=(a+b+carry)/10;
          }
          else carry=0;
     }

     if(idx_a==idx_b){
          ans[idx_bigger]=(char)(carry+'0');
     }
     else if(idx_a>0)
          while(idx_a-->0){
               int a=A[idx_a]-'0';
               ans[idx_bigger--]=(char)((a+carry)%10+'0');
               if(a+carry>=10){
                    carry=(a+carry)/10;
               }
          }
     else if(idx_b>0)
          while(idx_b-->0){
               int b=B[idx_b]-'0';
               ans[idx_bigger--]=(char)((b+carry)%10+'0');
               if(b+carry>=10){
                    carry=(b+carry)/10;
               }
          }
     for(int i=0; i<=end; i++){
          if(ans[0]=='0' && i==0 ) i++;
          if(ans[i]==0) continue;
          cout << ans[i];
     }
     return 0;
}
