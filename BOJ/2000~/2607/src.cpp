//https://www.acmicpc.net/problem/2607
#include <iostream>
#include <cstring>
using namespace std;

int origin_letter[26];
int cmp_letter[26];
int N;

void init(){
     for(int i=0; i<26; i++)
          cmp_letter[i]=0;
}

bool chk_cmp(int origin_l, int cmp_l){
     int chk1=0;
     int chk2=0;
     int cnt0=0;
     int cnt1=0;
     int cnt2=0;
     if(origin_l==cmp_l){
          for(int i=0; i<26; i++){
               if(origin_letter[i]!=cmp_letter[i]){
                    if(cnt0==0) {
                         cnt0++;
                         chk1=origin_letter[i]>cmp_letter[i] ? origin_letter[i]-cmp_letter[i]: cmp_letter[i]-origin_letter[i] ;
                    }
                    if(cnt0==1){
                         cnt0++;
                         chk2=origin_letter[i]>cmp_letter[i] ? origin_letter[i]-cmp_letter[i]: cmp_letter[i]-origin_letter[i] ;
                    }
                    if(cnt0>1){
                         return false;
                    }
               }
               else cnt1++;
          }
          if((chk1==1 &&chk2==1) ||cnt1==26) return true;
          else return false;
     }
     else{
          cnt1=0;
          for(int i=0; i<26; i++){
               cmp_letter[i]-=origin_letter[i];
               if(cmp_letter[i]>0) cnt1+=cmp_letter[i];
               if(cmp_letter[i]<0) cnt2-=cmp_letter[i];
          }
          if((cnt1==1&&cnt2==0)||(cnt1==0&&cnt2==1)) return true;
          else return false;
     }
     return true;
}

int main(){
     cin >> N;
     string origin;
     cin >> origin;
     int cnt=0;

     for(int i=0; i<origin.size(); i++ ){
          origin_letter[(int)origin[i]-'A']++;
     }


     for(int i=1; i<N; i++){
          init();
          string cmp;
          cin >> cmp;

          for(int j=0; j<cmp.size(); j++){
               cmp_letter[(int)cmp[j]-'A']++;
          }

          if(chk_cmp(origin.size(),cmp.size())) {cnt++;}
     }

     cout << cnt;
}
