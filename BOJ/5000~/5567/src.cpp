//https://www.acmicpc.net/problem/5567
#include <iostream>
using namespace std;
bool friendof1[501];
bool friendof2[501];
int frd[10000][2];

 int main()
 {
      int n,m,cnt;
      cin >>n >>m;

      cnt=0;
      for(int i=1; i<=m; i++)
      {
           int a,b;
           cin >> a >> b;

           frd[i][0]=a;
           frd[i][1]=b;

           if(a==1 && !friendof1[b]) { friendof1[b]=1; }
           if(b==1 && !friendof1[a]) { friendof1[a]=1; }
      }

      for(int i=2; i<=m; i++)
      {
           if(friendof1[i])
          {
                     for(int j=2; j<=m; j++)
                {
                     if(frd[j][0]==i && !friendof1[frd[j][1]])
                      {friendof2[frd[j][1]]=1; cnt++;}
                      if(frd[j][1]==i  && !friendof1[frd[j][0]])
                       {friendof2[frd[j][0]]=1; cnt++;}
                }}
}

      cout << cnt;
}
