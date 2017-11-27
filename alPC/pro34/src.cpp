#include <iostream>
using namespace std;

unsigned long reverse(unsigned long x)
{
  unsigned long y=0;

  while (x>0)
  {
    y= y*10 + x%10;
    x /=10;
  }
  return y;
}
int main(){
  int N, iter;
  cin >> N;
  for(int i=0; i<N; i++){
    unsigned long num;
    unsigned long re;
    cin >> num;

    iter=0;
    while(num !=(re=reverse(num)))
    {
      num+=re;
      iter++;
    }
    cout << iter << " " << num << endl;
  }
}
