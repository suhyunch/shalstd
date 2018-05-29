#include <iostream>
using namespace std;

char map[100][100];
int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> map[i];

    int k;
    cin >> k;

    if(k==1){
        //그대로
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << map[i][j];
            }cout <<'\n';
        }
    }
    else if(k==2){
        //좌우 대칭
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){
                cout << map[i][j];
            }cout <<'\n';
        }
    }
    else if(k==3){
        //상하대칭
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<n; j++){
                cout << map[i][j];
            }cout <<'\n';
        }
    }

    return 0;
}
