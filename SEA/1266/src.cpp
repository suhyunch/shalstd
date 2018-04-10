#include <iostream>
using namespace std;
int num[7]={2,3,5,7,11,13,17};
int combination[7]={ 153, 816, 8568, 31824, 31824, 8568, 18 };

int main(){
    int T;
    cin >> T;

    for(int tc=1; tc<=T; tc++){
        double a, b;
        double suma=0, sumb=0;
        cin >> a >> b;

        a/=100; b/=100;

        for(int i=0; i<7; i++){
             double proba=1, probb=1;
           	for(int j=0; j<18; j++){
                if(j<num[i]) {
                    proba*=a;
                    probb*=b;
                }
                else {
                    proba*=(1-a);
                    probb*=(1-b);
                }
            }
            proba*=combination[i];
            probb*=combination[i];
            suma+=proba;
            sumb+=probb;
        }
        suma=1-suma;
        sumb=1-sumb;
        cout << " :: " <<suma << " " << sumb << endl;

        double ans=1-suma*sumb;
        cout << "#" << tc ;
        cout << fixed;
        cout.precision(6);
        cout << " " <<ans << endl;
    }
}
