//https://www.acmicpc.net/problem/11004
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
     int n, k;
     vector<int> v;
     scanf("%d %d", &n, &k);
     k--;
     for(int i=0; i<n; i++) {
          int a;
          scanf("%d", &a);
          v.push_back(a);
     }
     nth_element(v.begin(), v.begin()+k, v.end());
     cout << v[k];
     return 0;
}
