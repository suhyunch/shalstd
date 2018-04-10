#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, Q;


int main(){
    int T;
    cin >> T;

    for(int tc=1; tc<=T; tc++){
        cin >> N >> M >> Q;
        int ans=0;
        int mx=0;
        int **arrt= new int*[N+1]; // 수열 저장
        for(int i=1; i<=N; i++){
            arrt[i]=new int[M];
            memset(arrt[i], 0, sizeof(int)*(M));
        }

        int *arr_n=new int[N+1]; // 각 배열의 원소 개수 저장
    	   memset(arr_n, 0, sizeof(int)*(N+1));

        while(M-->0){
            int a, b, v;
            cin >> a >> b >> v;
            for(int i=a; i<=b; i++){
                arrt[i][arr_n[i]]=v;
                arr_n[i]++;
                mx++;
            }
        }

        int *arr_tmp=new int[mx];
        memset(arr_tmp, 0, sizeof(int)*(mx));
        while(Q-->0){
            int x, y, j;
            cin >> x >> y >>j;
            int cnt=0;
            for(int i=x; i<=y; i++){
                for(int k=cnt; k<cnt+arr_n[i] ;k++){
                    arr_tmp[k]=arrt[i][k-cnt];
                }
                cnt+=arr_n[i];
            }
            sort(arr_tmp, arr_tmp+cnt);
            ans+=arr_tmp[j-1];

        }

        cout << "#" << tc << " " << ans <<endl;

    }
}
