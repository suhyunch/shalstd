//https://www.acmicpc.net/problem/9506
#include <iostream>
#include <cstring>
using namespace std;

void process(int n){
     int ans=1;
     int tmp[5000];
     memset(tmp, 0, sizeof(int)*5000);
     tmp[0]=1;
     int index=1;
     for(int i=2; i<=n/2; i++){
          if(n%i==0) {
               ans+=i;
               tmp[index++]=i;
          }
     }

     if(n==ans){
          cout << n << " = ";
          for(int i=0; i<index; i++){
               cout << tmp[i]<<" ";
               if(i!=index-1) cout <<"+ ";
          }
          cout << endl;
     }
     else cout <<n <<" is NOT perfect." <<endl;
}

int main(){
      while(1){
           int n;
           cin >> n;

           if(n==-1) break;

           process(n);
      }
}
