#include <iostream>
using namespace std;

int main()
{
  while(1)
  {
    int a,b;
    cin >> a >> b;

    if(a==0 && b==0) break;

    int carry=0;
    int carry1=0;
    for(int i=0; i<10; i++)
    {
      if(a==0&&b==0) break;
      if((a%10 + b%10+carry1)>=10){ carry++; carry1=1;}
      else carry1=0;
      a/=10; b/=10;
    }

    if(carry==0) cout << "No carry operation."<<endl;
    if(carry==1) cout << "1 carry operation."<<endl;
    if(carry>1) cout << carry <<" carry operations."<<endl;
  }
}
