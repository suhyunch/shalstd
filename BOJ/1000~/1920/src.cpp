//https://www.acmicpc.net/problem/1920
#include <iostream>
#include <algorithm>
using namespace std;
int A[100001];

bool find_x(int x,int start, int end)
{
    int m;
    while(end-start>=0){
        m=(end+start)/2;
        if(A[m]==x) return true;
        if(A[m]<x) start=m+1;
        else end=m-1;
    }
    return false;
}

int main()
{
  int N,M;
  scanf("%d",&N);
  bool chk=0;
  for(int i=0; i<N;i++)
    scanf("%d",A+i);

  scanf("%d",&M);
  sort(A,A+N);
  for(int i=0; i<M; i++)
  {
    chk=0;
    int x;
    scanf("%d",&x);
    chk=find_x(x, 0, N-1);
    printf("%d\n",chk);
  }
}
