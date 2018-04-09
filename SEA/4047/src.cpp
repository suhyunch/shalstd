#include <iostream>
using namespace std;

bool card[4][14];
//S, D, H, C
void init(){
     for(int i=0; i<4; i++){
          for(int j=0; j<14; j++){
               card[i][j]=0;
          }
     }
}
int main(){
     int T;
     cin >> T;

     for(int tc=1; tc<=T; tc++){
          init();
          int S=13;
          int D=13;
          int H=13;
          int C=13;
          bool chk=0;
          string s;
          cin >> s;

          for(int i=0; i<s.size(); i+=3){
               int alpha=0;
               if(s[i]=='S') S--;
               else if(s[i]=='D') {
                    D--;
                    alpha=1;
               }
               else if(s[i]=='H') {
                    H--;
                    alpha=2;
               }
               else if(s[i]=='C') {
                    C--;
                    alpha=3;
               }

               int tmp=(10*(s[i+1]-'0')+(s[i+2]-'0'));
               if(!card[alpha][tmp]){
                    card[alpha][tmp]=1;
               }

               else {
                    chk=1;
                    break;
               }
          }
          if(chk) cout <<"#"<<tc <<" ERROR"<<endl;
          else cout <<"#"<<tc <<" "<<S <<" " << D <<" " <<H <<" "<<C<<endl;
     }
}
