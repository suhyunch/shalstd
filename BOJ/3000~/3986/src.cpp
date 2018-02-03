//https://www.acmicpc.net/problem/3986
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
     int n;
     int cnt=0;
     cin >> n;

     for(int i=0; i<n; i++)
     {
          string s;
          cin >> s;
          int l=s.size();
          stack<char> st;

          for(int j=0; j<l; j++)
          {
               if(!st.empty() && st.top()==s[j]) st.pop();
               else  st.push(s[j]);
          }

          if(st.empty()) cnt++;
     }
     cout <<cnt;
}
