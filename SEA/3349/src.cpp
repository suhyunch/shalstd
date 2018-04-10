/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
int W, H, N, sx, sy, dex, dey;
int mn;
int visited[10001][10001];
int dx[6]={-1,0,-1,1,0,1};
int dy[6]={-1,-1,0,0,1,1};

void init(){
     for(int i=1; i<=W; i++){
          for(int j=1; j<=H; j++){
               visited[j][i]=0;
          }
     }
}
void dfs(int x, int y, int depth){
     visited[y][x]=depth;
    if(x==dex && y==dey) {
         if(mn>depth-1) mn=depth-1;
    }

    for(int i=0; i<6; i++){
        int nx=x+dx[i];
        int ny=y+dy[i];

        if(depth+1<=visited[ny][nx]) visited[ny][nx]=0;
        if(ny>0 && ny<=H && nx>0 && nx<=W && !visited[ny][nx]){
            dfs(nx, ny, depth+1);
        }
    }

}
int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		cin >> W >> H >> N >> sx >> sy;
        int ans=0;

        while(N-->1){
            cin >> dex >> dey;
            init();
            mn=100000001;
            visited[sy][sx]=1;
            dfs(sx, sy, 1);
            ans+=mn;
        	  sx=dex;
        	  sy=dey;
        }

        printf("#%d %d\n",test_case,ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
