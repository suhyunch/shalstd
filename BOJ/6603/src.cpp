//https://www.acmicpc.net/problem/6603
#include <iostream>
using namespace std;
int lotto[7];
int S[14];
bool visit[13]={0,};
int k;
bool chk;

void dfs(int n,int cnt)
{
     visit[n]=1;
          for(int i=1; ;i++)
          {
               int nn=n+i;
               lotto[cnt]=S[nn];

               if(cnt==6)
              {

                    for(int i=0; i<6; i++) cout << lotto[i] << " ";
                    cout << endl;
                    break;
              }
              if(nn>k) break;
               if(!visit[nn] && nn<=k) {dfs(nn, cnt+1);}
          }
          visit[n]=0;
}

int main()
{
     while(1)
     {
          cin >> k;
          if(!k) break;
          for(int i=1; i<=k; i++) cin >> S[i];
               dfs(0,0);
          cout << endl;
     }
}
