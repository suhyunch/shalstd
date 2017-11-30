//https://www.acmicpc.net/problem/2864
#include <iostream>
using namespace std;

int main()
{
  int A,B;
  cin >> A>>B;

  int sum_min=0;
  int sum_max=0;
  int x=A;
  int y=B;
  int ten=1;
  //minimize
  while(x>0 || y>0)
  {
    int k=x%10;
    int l=y%10;
    if(k==6) k=5;
    if(l==6) l=5;
    sum_min += (k+l)*ten;
    ten*=10;
    x/=10;
    y/=10;
  }
ten=1;
 //maximize
 while(A>0 || B>0)
 {
   int k=A%10;
   int l=B%10;
   if(k==5) k=6;
   if(l==5) l=6;
   sum_max += (k+l)*ten;
   ten*=10;
   A/=10;
   B/=10;
 }

cout << sum_min << " " << sum_max ;
}
