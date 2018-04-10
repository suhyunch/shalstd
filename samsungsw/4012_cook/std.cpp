#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;


int S[20][20], ans;
//시너지 행렬
bool C[20];
//음식 사용 여부 저장


void search(int N, int cnt, int f)
{
  if(cnt == N)
  {
    //음식 종류 저장하쇼
    int A = 0, B = 0;
    for(int i = 1; i <= N; i++)
    {
      for(int j = 1; j <= N; j++)
      {
        //음식체크
        if(i==j) continue;
        if(C[i] && C[j]) A += S[i][j];
        //A음식에 사용한 재료의 시너지는 A에 저장해준다.
        if(!C[i] && !C[j]) B += S[i][j];
        //A음식에 사용되지 않은 재료의 시너지는 B에 저장한다.
      }
    }
    ans = min(ans, abs(A-B));
    return;
  }
  if(f > 0)
  {
    //A음식에 사용할 음식의 갯수가 아직 남았다면?
    C[cnt] = true;
    search(N, cnt+1, f-1);
    //체크하고 남은 식재료 개수 줄여준다.
    C[cnt] = false;
  }
  search(N, cnt+1, f);
}

int main()
{
  int T;
  scanf("%d", &T);

  for (int tc  = 1; tc <= T; tc++)
  {
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= N; j++)
      {
        scanf("%d", &S[i][j]);
      }
    }

    ans = 2e9;
    //최소 계산 위한 최대값 저장
    search(N, 0, N/2);
    //모든 조합 탐색
    printf("#%d %d\n", tc, ans);
  }
  return 0;
}
