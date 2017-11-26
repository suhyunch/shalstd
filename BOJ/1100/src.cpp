//https://www.acmicpc.net/problem/1100
#include <iostream>
using namespace std;

int main()
{
  char map[8][8];

  for(int i=0; i<8; i++) for(int j=0; j<8; j++) cin >> map[i][j];

  int cnt=0;
  for(int i=0; i<8; i++)
  {
    for(int j=0; j<8; j++)
    {
      if(i%2) {  if(j%2 && map[i][j] == 'F') cnt++;}
      else {if(!(j%2) &&  map[i][j] == 'F') cnt++;}
    }
  }
  cout << cnt;
}
