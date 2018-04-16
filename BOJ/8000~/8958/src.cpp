#include <iostream>
#include <string>
using namespace std;

int score[80];
int main(){
    int n;
    cin >> n;
    while(n-->0){
        string s;
        cin >> s;
        int ans=0;
        if(s[0]=='O') score[0]=1;
        else score[0]=0;
        ans=score[0];
        for(int i=1; i<s.size(); i++){
            if(s[i]=='O')score[i]=score[i-1]+1;
            else score[i]=0;
            ans+=score[i];
        }
        cout << ans <<endl;
    }
}
