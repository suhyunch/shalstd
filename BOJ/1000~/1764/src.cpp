//https://www.acmicpc.net/problem/1764
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int N, M;
    vector<string> name;
    vector<string> ans;
    int cnt=0;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        string s;

        cin >> s;
        name.push_back(s);
    }

    while(M-->0){
        string s;
        cin >> s;

        for(int i=0;i<N;){
            if(s==name[i]){
                cnt++;
                ans.push_back(s);
                name.erase(name.begin()+i);
            }
            else i++;
        }
    }
   // cout << endl;
    sort(ans.begin(), ans.end());
    cout << cnt <<endl;
    for(int i=0; i<cnt; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
