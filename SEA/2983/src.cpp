#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int tc;
    cin >> tc;

    for(int T=1; T<=tc; T++){
        int sl;
        cin >> sl;

        string s;
        cin >> s;

        bool chk=0;
        int mx=0;
        for(int i=0; i<sl; i++){
            int cnt=0;
            for(int j=i+1; j<sl; j++){
                if(s[i]==s[j]){//검색 시작
                    for(int k=0; j+k<sl; k++){
                        if(s[i+k]==s[j+k]) cnt++;
                        else {
                            if(mx<cnt) mx=cnt;
                            cnt=0;
                            break;
                        }
                    }
                }
            }
        }
        cout<< "#"<<T << " "<< mx << endl;
    }
}
