//https://www.acmicpc.net/problem/5554
#include <iostream>
using namespace std;


int sum(){
     int a;
     int ans=0;

     for(int i=0; i<4; i++){
          cin >> a;
          ans+=a;
     }
     return ans;
}

int main(){
      int sum1=0;

      sum1=sum();

      cout << sum1/60 << endl << sum1%60;
}
