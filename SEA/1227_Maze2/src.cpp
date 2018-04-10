#include <iostream>
using namespace std;
char map[100][100];
bool visited[100][100];
int sy, sx;
bool chk;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void input(){
    for(int i=0; i<100; i++) cin >> map[i];
}
void dfs(int y, int x){
     for(int i=0; i<4; i++){
          visited[y][x]=1;
          int ny=y+dy[i];
          int nx=x+dx[i];

          if(map[ny][nx]=='3') chk=1;
          if(ny>=0 && ny<100 && nx>=0 && nx<100 && !visited[ny][nx] && map[ny][nx]=='0')
             dfs(ny, nx);
          visited[y][x]=0;
       }
}

int main(){
    int T;
    while(1){
        cin >> T;
        cout << "#" << T <<" " ;
    	   input();
        for(int i=0; i<100; i++)
            for(int j=0; j<100; j++){
                if(map[i][j]=='2'){
                    sy=i; sx=j;
                }
            }
        chk=0;
        dfs(sy,sx);

        cout << chk << endl;
        if(T==10) break;
    }
}
