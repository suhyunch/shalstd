//https://www.acmicpc.net/problem/4344
#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int C;
  cin >> C;
  for(int i=0; i<C; i++)
  {
    int N;
    int sum=0;
    int avg;
    int cnt=0;
    stack<int> s;
    cin >> N;
    for(int j=0; j<N; j++)
    {
        int x;
        cin >> x;
        sum+=x;
        s.push(x);
    }
    avg=sum/N;

    for(int j=0; j<N; j++)
    {
      int x=s.top();
      if(x>avg) cnt++;
      s.pop();
    }

    float percent = ((float) cnt/ (float) N )*100;

    cout << fixed;
    cout.precision(3);
    cout << percent << "%" << endl;
  }
}
