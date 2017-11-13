#include <iostream>
using namespace std;
int heap[100000];
int max(int a, int b) {return a>b? a:b;}

void insert(int curr) // 삽입할 값 x, 현재 노드 위치 curr
{
  int parent=curr/2;
  if(heap[parent]<heap[curr])
  {
    int tmp = heap[parent];
    heap[parent]= heap[curr];
    heap[curr]= tmp;
    if(parent !=1) insert(parent);
  }
  else return;
}

void deletef(int curr, int node)//현재 위치, 현재 노드 개수
{
  int lc=curr*2;
  int rc=curr*2 +1;
  if(lc>node) return;
  if(heap[curr]>max(heap[lc],heap[rc])) return;
  if(heap[lc]>heap[rc])
  {
    int tmp=heap[lc];
    heap[lc]=heap[curr];
    heap[curr]=tmp;
    deletef(lc,node);
    }
    else
    {
      int tmp=heap[rc];
      heap[rc]=heap[curr];
      heap[curr]=heap[rc];
      deletef(rc,node);
      }
}

int main()
{
  int T;
  cin >> T;
  int node=0;
  for(int tc=1; tc<=T; tc++)
  {
    int n;
    cin >> n;
    for(int i=1; i<=node; i++) heap[i]=0;//초기화
    node=0;

    cout << "#" << tc << " ";
    for(int i=0; i<n; i++)
    {
      int order;
      cin >> order;
      if(order==1)
      {
        node++;
        cin>>heap[node] ;
        if(node!=1) insert(node);
      }
      else
      {
        if(node==0) cout << "-1 ";
        else
        {
          cout << heap[1] << " ";
          heap[1]=heap[node];
          heap[node]=0;
          node--;
          if(node != 1)  deletef(1, node);
        }
      }
    }
    cout << endl;
  }
}
