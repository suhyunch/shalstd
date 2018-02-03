//https://www.acmicpc.net/problem/12790
#include <iostream>
using namespace std;

int main()
{
     int T;
     cin >> T;
     int hp, mp, atk,def;
     int a,b,c,d,ans;

     for(int i=0; i< T; i++)
     {
          cin >> hp >> mp >> atk >> def >> a >> b >> c >> d;

          hp+=a;
          mp+=b;
          atk+=c;
          def+=d;

          if(hp<1) hp=1;
          if(mp<1) mp=1;
          if(atk<0) atk=0;

          ans=hp+5*mp+2*atk+2*def;

          cout << ans << endl;
     }
}
