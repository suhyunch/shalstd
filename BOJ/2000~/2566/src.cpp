//https://www.acmicpc.net/problem/2566
#include <iostream>
using namespace std;

int main(){
     int mx=0;
     int ci=0, ri=0;
     int x;
     for(int i=1; i<=9; i++){
          for(int j=1; j<=9; j++){
               cin >> x;

               if(x>mx) {
                    mx=x;
                    ri=i;
                    ci=j;
               }
          }
     }

     cout <<  mx << endl << ri <<" "<< ci <<endl;
}
