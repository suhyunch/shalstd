#include <iostream>
#include <algorithm>
using namespace std;
bool map[100][100] ;
bool visit[100][100];
int v[5000];
int n_area;
int nv;
int M, N, K;

int dx[4]={ 1, -1, 0, 0};
int dy[4]={ 0, 0, 1, -1};

void dfs(int y, int x)
{
	nv++; //넓이
	for(int i=0; i<4; i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];

		if(ny>=0 && ny<M && nx>=0 && nx< N && !map[ny][nx] && !visit[ny][nx])
		{
			visit[ny][nx]=1;
			dfs(ny, nx);
		}
	}
}

int main()
{
	cin >> M >> N >> K;

	/*input*/
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = y1; j < y2; j++)
			{
				for (int k = x1; k < x2; k++)
				map[j][k] = 1;
			}
	}

	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++)
			if(!map[i][j] && !visit[i][j])
			{
				nv=0;
				visit[i][j]=1;
				dfs(i,j);
				v[n_area]=nv;
				n_area++;
			}

		sort(v, v+n_area);
		cout << n_area<<endl;
		for(int i=0; i<n_area; i++) cout << v[i] << " ";
}
