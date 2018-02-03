//https://www.acmicpc.net/problem/9507
#include <iostream>
using namespace std;
long long koong[68];

 int main()
 {
      int t;
      cin >> t;

      for(int i=0; i<t; i++)
      {
           int n;
           cin>>n;

           for(int j=0; j<=n; j++)
           {
                if(koong[j]>0) continue;
                if(j<2) koong[j]=1;
                else if(j==2) koong[j]=2;
                else if(j==3) koong[j]=4;
                else koong[j]=koong[j-1]+koong[j-2]+koong[j-3]+koong[j-4];
           }

           cout << koong[n] << endl;
      }
}
