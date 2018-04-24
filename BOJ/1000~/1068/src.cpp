//https://www.acmicpc.net/problem/1068
#include <iostream>
#include <vector>
using namespace std;

int tree[50][50];//tree[i][0] : i 번째 노드의 자식 수
               //tree[i][j] : i번째 노드의 자식 index
int n, d, ans;
void search(int tmp);
int main(){
     cin >> n;
     int root;

     for(int i=0; i<n; ++i){
          int p;
          cin >> p;
          if(p==-1) root=i;
          else{
               tree[p][0]++;
               tree[p][tree[p][0]]=i;
          }
     }

     cin >> d;
     if(root==d) {
          cout << ans;
          return 0;
     }
     int tmp=root;
     search(tmp);
     cout << ans;
     return 0;
}

void search(int tmp){
     int k=tree[tmp][0];
     for(int i=1; i<=k; i++){
          int next=tree[tmp][i];
          if(next==d) {
               if(tree[tmp][0]==1) ans++;
               continue;
          }
          if(tree[next][0]!=0)search(next);
          else ++ans;
     }
     return;
}
