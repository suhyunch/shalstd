//https://www.acmicpc.net/problem/2810
#include <iostream>
using namespace std;

int main(){
    int N;
    char chair[50];
    cin >> N;

    int ans=1;
    bool chk=0;
    for(int i=0; i<N; i++) {
        cin >> chair[i];
        if(chair[i]=='S') ans++;
        if(chair[i]=='L'){
            if(!chk) chk=1;
            else {
                ans++;
                chk=0;
            }
        }
   }

    if(ans<N) cout << ans;
    else cout << N;
}
