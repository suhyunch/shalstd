//https://www.acmicpc.net/problem/1302
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct book{
     int idx;
     int cnt;
     string title;
     book();
     book(int idx, string title, int cnt) : idx(idx), title(title), cnt(cnt) {}
};

bool cmp(book a, book b){
     if(a.cnt != b.cnt)
          return a.cnt> b.cnt;
     else {
          if(a.title.compare(b.title) < 0) return true;
          else return false;
     }
}
int main(){
     vector<string> v;
     vector<book> l;
     int n;
     cin >> n;
     for(int i=0; i<n; ++i){
          string s;
          cin >> s;
          v.push_back(s);
     }
     sort(v.begin(), v.end());

     string m=v[0];
     int idx=0;
     l.push_back(book(0, v[0], 1));
     for(int i=1; i<n; ++i){
          if(v[i].compare(v[i-1])==0) l[idx].cnt++;
          else{
               l.push_back(book(i, v[i], 1));
               idx++;
          }
     }
     sort(l.begin(), l.end(), cmp);
     cout << l[0].title;
     return 0;
}
