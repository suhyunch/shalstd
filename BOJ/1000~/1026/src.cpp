//https://www.acmicpc.net/problem/1026
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
     return a>b;
}
int main(){
     int n;

     cin>> n;
     vector<int> A;
     vector<int> B;
     for(int i=0; i<n; i++) {
          int a;
          cin >> a;
          A.push_back(a);
     }
     for(int i=0; i<n; i++) {
          int b;
          cin >> b;
          B.push_back(b);
     }

     sort(B.begin(), B.end());
     sort(A.begin(), A.end(), cmp);
     int ans=0;

     for(int i=0; i<n; i++){
          ans+=A[i]*B[i];
     }
     cout << ans;

     return 0;
}
