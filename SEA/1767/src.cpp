#include <iostream>
using namespace std;
bool map[12][12];
int core[12][3]; // core[i][0] :i번째 코어 y좌표, core[i][1]: i번째 코어 x좌표, core[i][2] : 가장자리에 붙은 것인지 체크
int line[12][12];
int mn=401;
int N;
int dy[4]={0,0,1,-1};
int dx[4]={1,-1,0,0};

void init(){
    for(int i=0; i<12; i++)
        for(int j=0; j<12; j++){
            map[i][j]=line[i][j]=0;
            if(j<3) core[i][j]=-1;
        }
}

void dfs(int idx, int ncore, int l){
    if(idx==ncore-1) {
        if(l<mn) mn=l;
        return;
    }
    int tmpl=0;
    int ly=core[idx][0];
    int lx=core[idx][1];
    for(int i=0; i<4; i++){
        int cnt=0;

        while(1){
            if(ly==0 || ly==N-1 || lx==0 || lx==N-1) break;
            ly=ly+dy[i];
            lx=lx+dx[i];
            cnt++;
            tmpl++;
            if(line[ly][lx]==1 || line[ly][lx]==2) {
                while(cnt-->0)
                    if(line[ly][lx]==1) line[ly][lx]=0;
                ly-=dy[i];
                lx-=dx[i];
                tmpl=0;
                break;
            }
            line[ly][lx]=1;
        }
        cout << endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
               cout << line[i][j] << " ";}
            cout << endl;
        }
        cout << idx << " " << l << " " << tmpl << endl;
        dfs(idx+1, ncore, l+tmpl);
    }
}

int main(){
    int tc;
    cin >> tc;

    for(int T=1; T<=tc; T++){
        init();

        cin >> N;
        int cnt=0; // core 갯수
        int cnt2=0; // 가장자리에 붙은 core갯수

        //input
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> map[i][j];

                if(map[i][j]==1) {
                    core[cnt][0]=i;
                    core[cnt][1]=j;
                    line[i][j]=2;
                    cnt++;
                    /*if(core[cnt][0]==0 || core[cnt][0]==N-1 || core[cnt][1]==0 || core[cnt][1]==N-1) {
                        core[cnt][2]=1;
                        cnt2++;
                   }*/
                }
            }
        }
        cout << cnt << endl;

        cout << "this is map" << endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << map[i][j] << " ";}
            cout << endl;
        }

        cout << endl;
        cout << "this is core status " << endl;

        for(int i=0; i<12; i++){
             cout << i << " : ";
             for(int j=0; j<3; j++)
                cout << core[i][j] << " ";
                cout << endl;
        }
        cout << endl;
        cout << "this is line" << endl;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << line[i][j] << " ";}
            cout << endl;
        }


        dfs(0, cnt, 0);

        cout << "#" << T << " " << mn << endl;
    }
}
