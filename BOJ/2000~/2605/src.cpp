//https://www.acmicpc.net/problem/2605
#include <iostream>
#include <cstring>
using namespace std;
int students[101];
int ans[101];
int n;
void order(){
     int x;
     cin >> n >> x;
     ans[1]=1;

     for(int i=2; i<=n; i++){
          cin >> x;

          for(int j=i-1; j>=i-x; j--){
               ans[j+1]=ans[j];
          }
          ans[i-x]=i;
     }
}

void output(){
     for(int i=1; i<=n; i++) cout << ans[i] << " ";
}
int main(){
     order();
     output();
}
