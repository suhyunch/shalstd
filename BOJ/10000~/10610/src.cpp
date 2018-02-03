//https://www.acmicpc.net/problem/10610
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int num1[10005];

int main()
{
     string num;
     cin >> num;
     int l=num.size();
     int sum=0;
     bool cnt=0;
     for(int i=0; i<l; i++)
     {
          sum+=(num[i]-'0');
          num1[i]=num[i]-'0';
          if(num[i]-'0' == 0) cnt++;
     }

     if((sum%3!=0) || !cnt ) {
          cout << "-1";
          return 0;
     }
     sort(num1, num1+l);

     sum=0;
     for(int i=l-1;i>=0; i--)
     {
          sum*=10;
          sum+=num1[i];
     }

     cout << sum;
}
