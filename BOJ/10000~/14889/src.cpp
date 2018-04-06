//https://www.acmicpc.net/problem/14889
#include <iostream>
#include <algorithm>
using namespace std;
int abs(int a, int b) { return (a-b)>(b-a)? (a-b):(b-a); }

int s[21][21];
bool start[20];
int ss;//start score
int ls;//link score
int n;
int mn=1e9;

void dfs(int idx, int depth);
int main()
{
      cin >> n;

      for(int i=0; i<n; i++)
           for(int j=0; j<n; j++){
                if(s[j][i]==0) cin >> s[i][j];
                else{
                     int a;
                     cin >> a;
                     s[j][i]+=a;
                }
           }

     for(int i=0; i<=n/2; i++){
          start[i]=true;
          dfs(i, 1);
          start[i]=false;
     }
     cout << mn;
     return 0;
}

void dfs(int idx, int depth){
     if(depth==n/2){
          //능력치 계산
          for(int i=0; i<n; i++){
               if(start[i]) {
                    for(int j=0; j<n; j++){
                         if(start[j]) ss+=s[i][j];
                    }
               }
               else{
                    for(int j=0; j<n; j++){
                         if(!start[j]) ls+=s[i][j];
                    }
               }
          }
          mn=min(mn, abs(ss, ls));
          ss=0;
          ls=0;

          return;
     }

     for(int i=idx+1; i<n; i++){
          start[i]=true;
          dfs(i, depth+1);
          start[i]=false;
     }
     return;
}
