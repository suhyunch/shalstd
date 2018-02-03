//https://www.acmicpc.net/problem/2306
#include <iostream>
#include <string>
using namespace std;
int dp[501][501];

int main()
{
     string s;
     cin >>s;

     int l=s.size();

     if((s[0]=='a' && s[1]=='t') || (s[0]=='g' && s[1]=='c')) dp[2][1]=2;
     cout << s[0] <<endl << s[1] << endl;

     int maxdp=0;
     for(int i=2; i<=l; i++)
     {
          int tmpi=i+1;
          if((s[i]=='t' && s[i-1]=='a')||(s[i-1]=='g' && s[i]=='c' )) dp[tmpi][i]=2;

          cout << s[i] << " " << tmpi << endl;
          for(int j=i-1; j>=0; j--)
          {
               maxdp=0;
               int tmpj=j+1;
               cout << " " <<s[j] <<" "<< tmpj << endl;
               if((s[i]=='t' && s[i-1]=='a')||(s[i-1]=='g' && s[i]=='c' ))
               {
                    dp[tmpi][tmpj]=dp[i][j]+dp[j][1]+maxdp+2;
               }
               else
               {
                    dp[tmpi][tmpj]=dp[j][1]+dp[tmpj][i];
               }


                    cout << dp[tmpi][tmpj] << endl;
          }
          cout << endl;
     }

     int maxl=0;
     for(int i=1; i<=l; i++)
     {
          if(dp[l+1][i]>maxl) maxl=dp[l+1][i];
     }

     cout << maxl;

}
