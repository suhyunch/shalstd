#include <iostream>
using namespace std;
int min(int a, int b)
{ return a > b? b:a; }
int min(int a, int b, int c)
{ return min(a,b) > c ? c: min(a,b);}

int main()
{
  int tc;
  cin >> tc;
  for(int T=1; T<=tc; T++)
  {
    int cost[4];
    for(int i=0; i<4; i++) cin >> cost[i];
    int plan[13];
    for(int i=1; i<=12; i++) cin >> plan[i];

    int d[13][3];
    d[1][0]=cost[0]*plan[1];
    if(plan[1]!=0)
    {
      d[1][1]=cost[1];
      d[1][2]=cost[2];
   }
   else
   {
         d[1][1]=0;
         d[1][2]=0;
      }

      for(int i=1; i<=12; i++)
      {
        for(int j=0; j<3;j++)
          cout << d[i][j] << "  ";
        cout << endl;
      }
      cout << endl;

    for(int i=2; i<=12; i++)
    {
      bool x;
      if(plan[i]==0) x=0;
      else x=1;
      cout << "x : "<<x << endl;
      if(i<4)
      {
        d[i][0]=min(d[i-1][0],d[i-1][1])+plan[i]*cost[0];
        d[i][1]=min(d[i-1][0],d[i-1][1])+cost[1]*x;
        d[i][2]=cost[2]*x;
      }
    else
    {
      d[i][0]=min(d[i-1][0],d[i-1][1],d[i-1][2])+plan[i]*cost[0];
      d[i][1]=min(d[i-1][0],d[i-1][1],d[i-1][2])+cost[1]*x;
        //d[i][2]는 3가지 경우가 각각 2,2,3가지 총 7가지 경우 가능
        int cmp1=min(d[i-3][0]+ cost[2],d[i-3][1]+ cost[2],d[i-3][2]+ cost[2]);
        int cmp2=min(d[i-2][0]+ cost[2],d[i-2][1]+ cost[2],d[i-2][2]+ cost[2]);
        int cmp3=min(d[i-1][0]+ cost[2]*x,d[i-1][1]+ cost[2]*x,d[i-1][2]+ cost[2]*x);
      d[i][2]=min(cmp1,cmp2,cmp3) ;
    }
    cout << i << endl;
    for(int i=1; i<=12; i++)
    {
      for(int j=0; j<3;j++)
        cout << d[i][j] << "  ";
      cout << endl;
    }
    cout << endl;
  }
  for(int i=1; i<=12; i++)
  {
    for(int j=0; j<3;j++)
      cout << d[i][j] << "  ";
    cout << endl;
  }
  int min_cost=cost[3];
  for(int i=0; i<3; i++)
    if(d[12][i]< min_cost) min_cost=d[12][i];

  cout << "#" << T << " "<<  min_cost << endl;
 }
}
