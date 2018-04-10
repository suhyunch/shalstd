#include <iostream>
#include <cmath>
#define mod 1000000007
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int tc=1; tc<=t; tc++){
        int n,m;
        cin >> n >> m;
        double x=pow(n,m)%mod;
        cout << x << endl;
        int ans=0;
        for(int i=1; i<=x; i++){
            if(x%i ==0)
                ans=(ans+i)%mod;
        }
        cout << "#" << tc << " " << ans << endl;
    }
}
