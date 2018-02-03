//https://www.acmicpc.net/problem/1946
#include <iostream>
using namespace std;
int score[2][100000];

 int main()
 {
      int t;
      cin >> t;
      for(int i=0; i<t; i++)
      {
           int n, standard0, standard1, max1,cnt;
           cin >> n;

           for(int j=0; j<n; j++)
               cin >> score[0][j] >> score[1][j];

          max1=0;
          cnt=n;
          for(int j=0; j<n; j++)
          {
               standard0=score[0][j];
               standard1=score[1][j];

               for(int k=0; k<n; k++)
                    if(standard0<score[0][k] && standard1<score[1][k])
                         cnt--;

               if(max1<cnt) max1=cnt;
          }

          cout << max1 << endl;
      }
}
