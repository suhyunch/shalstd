//https://www.acmicpc.net/problem/1657
#include <iostream>
using namespace std;

int max(int a, int b)
{ return a > b ? a: b;}
int max(int a, int b, int c)
{ return max(a,b) > c ? max(a,b) : c;}


int dp[14][14][3];
char grade[14][14];
int grade1[6][6]={{10,8,7,5,0,1}, {8,6,4,3,0,1},{7,4,3,2,0,1},{5,3,2,2,0,1},{0,0,0,0,0,0},{1,1,1,1,0,0}};

int main()
{
     int n, m;
     int tb1,tb2;
     cin >> n >> m;

     /*입력*/
     for(int i=0; i<n; i++)
          cin >> grade;

     tb1=grade[0][0]-'A';
     tb2=grade[1][0]-'A';
     dp[0][0][0]=grade1[tb1][tb2];
     tb1=grade[0][0]-'A';
     tb2=grade[0][1]-'A';
     dp[0][0][1]=grade1[tb1][tb2];
     dp[0][0][2]=0;

      for(int i=0;i<n;i++)
      {
           for(int j=0; j<n; j++)
           {
                if(!i && !j) continue;
                tb1=grade[i][j]-'A';
                tb2=grade[i+1][j]-'A';
                dp[i][j][0]=grade1[tb1][tb2]+max(dp[i][j-1][0],dp[i][j-1][2]);

                tb1=grade[i][j]-'A';
                tb2=grade[i][j+1]-'A';

           }
      }
}
