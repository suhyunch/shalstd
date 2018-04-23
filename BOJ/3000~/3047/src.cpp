//https://www.acmicpc.net/problem/3047
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
     int order[3];
     char abc[3];
     int num[3];
     for(int i=0; i<3; i++) cin >> num[i];
     cin >> abc;
     for(int i=0; i<3; i++) {
          order[i]=abc[i]-'A';
     }
     sort(num, num+3);
     for(int i=0; i<3; i++) cout << num[order[i]]<<" ";
     return 0;
}
