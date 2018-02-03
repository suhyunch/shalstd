//https://www.acmicpc.net/problem/14888
#include <iostream>
using namespace std;
int n;
int a[100];
int op[4];
int resultmax=-1000000001, resultmin=1000000001;

void dfs(int now,int result)
{
     if(now==n)
     {
          resultmax=resultmax>result ? resultmax : result;
          resultmin=resultmin<result ? resultmin : result;
          return;
     }

     if(op[0]!=0)
     {
          op[0]--;
          dfs(now+1, result+a[now]);
          op[0]++;
     }

     if(op[1]!=0)
     {
          op[1]--;
          dfs(now+1, result-a[now]);
          op[1]++;
     }

     if(op[2]!=0)
     {
          op[2]--;
          dfs(now+1, result*a[now]);
          op[2]++;
     }

     if(op[3]!=0)
     {
          op[3]--;
          dfs(now+1, result/a[now]);
          op[3]++;
     }
}

int main()
{

      cin >> n;

      for(int i=0; i<n; i++) cin >> a[i];
      for(int i=0; i<4; i++) cin >> op[i];

      dfs(1, a[0]);

      cout << resultmax << endl << resultmin;
}
