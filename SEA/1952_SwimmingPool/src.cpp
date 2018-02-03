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
    d[0][1]=d[0][2]=d[0][0]=0;
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
    for(int i=2; i<=12; i++)
    {
      bool x;
      if(plan[i]==0) x=0;
      else x=1;
      cout << i << endl;
      if(i<4)
      {
        d[i][0]=min(d[i-1][0],d[i-1][1])+plan[i]*cost[0];
        d[i][1]=min(d[i-1][0],d[i-1][1])+cost[1]*x;
        if(plan[i]==0) d[i][2]=0;
        else d[i][2]=cost[2];
      }
    else
    {
      d[i][0]=min(d[i-1][0],d[i-1][1],d[i-1][2])+plan[i]*cost[0];
      d[i][1]=min(d[i-1][0],d[i-1][1],d[i-1][2])+cost[1]*x;
      d[i][2]=min(d[i-1][0]+ cost[2]*x,d[i-1][1]*x+ cost[2]*x,d[i-3][2]+ cost[2]*x) ;
    }
    for(int i=1; i<13; i++ )
    {
      for(int j=0; j<3; j++)
      cout << d[i][j] << "  ";
      cout << endl;
    }
    cout << endl;
  }
  int min_cost=cost[3];
  for(int i=0; i<3; i++)
    if(d[12][i]<= min_cost) min_cost=d[12][i];

  cout << "#" << T << " "<<  min_cost << endl;
 }
}
