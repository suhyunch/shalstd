#include <iostream>
using namespace std;

int num[1001];

int main(){
    for(int i=2; i<=1000; i++){
        for(int j=1; i*j<=1000; j++){
            num[i*j]++;
        }
    }

    int N;
    cin >> N;
    int ans=0;
    while(N-->0){
        int tmp;
        cin >>tmp;
        if(num[tmp]==1) ans++;
    }
    cout << ans;
}
