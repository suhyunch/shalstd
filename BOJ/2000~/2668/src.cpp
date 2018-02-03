//https://www.acmicpc.net/problem/2668
#include <iostream>
using namespace std;
int matrix[101];
bool visit[101];
int max1;
int cnt;
bool chk;
void dfs_find(int n)
{
  cnt++;
  visit[n]=1;
  int nn=matrix[n];
  cout << nn << "  " <<  max1 << "  "  << cnt << endl;
  if(!visit[nn])
    dfs_find(nn);
  else
  {
    if(max1<cnt) {
      max1=cnt;
      chk=1;
  }
  cout  << "  end1" << endl;
}
}

int main()
{
  int N;
  int index;
  cin >> N;

  for(int i=1; i<=N; i++)
    cin >> matrix[i];

  for(int i=1; i<=N; i++)
  {
    for(int j=1; j<=N; j++) visit[j]=0;
    cnt=0;
    chk=0;
    dfs_find(i);
    if(chk) index=i;
  }

  cout <<cnt <<endl<< index;
}
