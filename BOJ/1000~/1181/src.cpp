//https://www.acmicpc.net/problem/1181
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


bool cmp(string a, string b){
     if(a.size() < b.size()) return 1;
     if(a.size() == b.size()){
          return a.compare(b)<0 ? 1 : 0;
     }
     return 0;
}
int main(){
     int n;
     cin >> n;
     vector<string> v;
     for(int i=0; i<n; i++){
          string s;
          cin >> s;
          v.push_back(s);
     }
     sort(v.begin(), v.end(), cmp);
     cout << v[0]<<endl;
     for(int i=1; i<n; i++){
          if(v[i]==v[i-1]) continue;
          cout << v[i] <<endl;
     }
     return 0;
}
