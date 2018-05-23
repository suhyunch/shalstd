//https://www.acmicpc.net/problem/10610
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
     string num;
     cin >> num;
     int l=num.size();
     int sum=0;
     bool chk=0;
     vector<char> v;
     for(int i=0; i<l; i++)
     {
          sum+=(num[i]-'0');
          if(num[i]-'0'==0) chk=true;
          v.push_back(num[i]);
     }

     if(sum%3!=0 || !chk) {
          cout << "-1";
          return 0;
     }
     sort(v.begin(), v.end());

     sum=0;
     if(sum%30!=0){
          cout << "-1";
          return 0;
     }

     for(int i=l-1; i>=0; --i)
     {
          cout << v[i];
     }
     return 0;
}
