//https://www.acmicpc.net/problem/2309
#include <iostream>
#include <algorithm>
using namespace std;
int h[10];

int main()
{
     int sum=0;
     bool chk=0;
     for(int i=1; i<=9; i++) { cin >> h[i]; sum+=h[i]; }
     sort(h+1,h+10);

     bool index[10]={0,};

     for(int i=1; i<=8; i++)
     {
          for(int j=i+1; j<=9; j++)
          {
               if(sum-h[i]-h[j]==100)
               {
                    index[i]=1; index[j]=1;
                    chk=1;
                    break;
               }
          }
          if(chk) break;
     }

     for(int i=1; i<=9; i++)
          if(!index[i]) cout << h[i] << endl;
}
