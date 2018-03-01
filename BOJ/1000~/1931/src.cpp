//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define lli long long int

 int main()
 {
      int n;
      cin >> n;

      vector<pair<lli, lli> > arr;

      for(int i=0; i<n; i++){
           int a, b;
           cin >> a >> b;
           arr.push_back(pair<lli, lli>(b,a));
      }
      sort(arr.begin(), arr.end());

      int cnt=1;
      int end=arr[0].first;
      for(int i=1; i<n; i++){
           if(end<=arr[i].second){
                end=arr[i].first;
                cnt++;
           }
      }

      cout << cnt << endl;

      return 0;
}
