#include <iostream>
using namespace std;
int a[10][3];
int b[10][3];
//a[i][0] :: 창구 i가 접수에 걸리는 시간, a[i][1] 현재 이용 고객, a[i][2] 작업 끝나는 시간
//b[i][0] :: 창구 i가 정비에 걸리는 시간, b[i][1] 현재 이용 고객, b[i][2] 작업 끝나는 시간
int t[1001];
int k[2][1001];//k[0][i] i번째 고객의 이용접수창구, k[1][i] i번째 고객의 이용정비창구

int main()
{
     int t;
     cin >> t;

     for(int tc=1; tc<=t; tc++)
     {
          int N, M, K, A, B;
          cin >>  N >> M >> K >> A >> B;
          // N 접수창구, M 정비창구, K 고객수, A 이용접수창구, B 이용정비창구
          for(int i=1; i<=N; i++)
               cin >> a[i][0];
          for(int i=1; i<=M; i++)
               cin >> b[i][0];
          for(int i=1; i<=K; i++)
               cin >> t[i];

          int anow=1, bnow=0;
          for(int time0=0; ; time0++)
          {
               for(int i=1; i<=N; i++)
               {if(a[i][2]==time0) a[i][1]=0;}
               for(int i=1; i<=M; i++)
               {if(b[i][2]==time0) b[i][1]=0;}


               for(int i=1; i<=K; i++)
               {
                    if(time0==t[i])
                    {
                         for(int j=1; j<=N; j++)
                         {
                              if(a[j][1]==0) //이용객이 없으면
                              {
                                   a[j][1]=i;
                                   a[j][2]=time0+a[j][0];
                              }
                         }
                    }
               }
          }
     }
}
