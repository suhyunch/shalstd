#include <iostream>
#include <map>
using namespace std;
#define MOD 1000000007
char map2[500][500];

int N, ans;

struct cells{

    int sy, sx, ey, ex;
    cells(int sy, int sx, int ey, int ex) :
        sy(sy), sx(sx), ey(ey), ex(ex) { }

    bool operator <(const cells& other) const
    {
        return ((sy != other.sy) || (sx != other.sx) ||
               (ey != other.ey) || (ex != other.ex));
    }
};
map<cells, int> dp;
int dy[2]={0, 1};
int dx[2]={1, 0};
int solve(int sy, int sx, int ey, int ex);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
          cin >> N;
          for(int i=0; i<N; i++)
               cin >> map2[i];
          if(map2[0][0]!= map2[N-1][N-1]) {
               cout << "#" << test_case <<" 0" <<endl;
          }
          else{

               cout << "#" << test_case <<" " << solve(0, 0, N-1, N-1) << endl;
          }
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int solve(int sy, int sx, int ey, int ex){ // dfs
     if(sy>=N || sx>=N || ey<0 || ex<0 ) return 0;
     if(map2[sy][sx]!=map2[ey][ex]) return 0;
     if(sy==ey && sx==ex) return 1;
     if (dp.find(cells(sy, sx, ey, ex)) != dp.end())
        return dp[cells(sy, sx, ey, ex)];

     int ret=0;
     ret=(ret+solve(sy+1, sx, ey-1, ex))%MOD;
     ret=(ret+solve(sy+1, sx, ey, ex-1))%MOD;
     ret=(ret+solve(sy, sx+1, ey-1, ex))%MOD;
     ret=(ret+solve(sy, sx+1, ey, ex-1))%MOD;

     dp[cells(sy, sx, ey, ex)] = ret%MOD;

     return ret;
}
