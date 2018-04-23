//https://www.acmicpc.net/problem/1427
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
     string num;
     cin >> num;
     vector<int> v;
     for(int i=0; i<num.size(); i++){
          v.push_back(num[i]-'0');
     }
     sort(v.begin(),v.end());
     for(int i=num.size()-1; i>=0; i--){
          cout << v[i];
     }
     return 0;
}
