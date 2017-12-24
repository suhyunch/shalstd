#include <iostream>
using namespace std;

int map[22][22];
bool visit[27];//A=1, B=2, C=3,... ,Z=26
int cnt;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int y, int x, int curr)
{
	int N=0;

	for (int i = 0; i<4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (map[ny][nx]>0 && !visit[map[ny][nx]])
		{
			visit[map[ny][nx]] = 1;
			dfs(ny, nx,map[ny][nx]);
			visit[map[ny][nx]] = 0;
		}
	}
	for(int i=1; i<=27; i++) if(visit[i]) N++;
	if(cnt<N) cnt=N;
}


int main()
{
	int R, C;
	cin >> R >> C;

	//input
	for (int i = 0; i < R; i++)
	{
		char str[20];
		cin >> str;
		for (int j = 1; j <= C; j++)
		{/*A아스키 코드 65, 1 아스키코드 49,
		 1(숫자)=1(문자)-'0'
		 A를 문자 1로 : A(65)-49=16.
		 문자 1을 숫자 1로 : 49-'0'
		 -> A를 숫자 1로 : A-16-'0';*/
			map[i+1][j] = str[j - 1]-16-'0';
		}
	}
	visit[map[1][1]]=1;
	dfs(1, 1, map[1][1]);
	cout << cnt;
}
