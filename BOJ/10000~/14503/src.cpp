#include <iostream>
using namespace std;

struct robot {
	int r;
	int c;
	int dir;
};

int main()
{
	int N, M;
	cin >> N >> M;

	bool map[50][50] ;
  /*initialization*/
  for(int i=0; i<50; i++) for(int j=0; j<50; j++) map[i][j]=1;

	robot x;
	cin >> x.r >> x.c >> x.dir;

	int cnt = 0;
	for (int i = 0; i<N; i++) for (int j = 0; j<M; j++) cin >> map[i][j];

	while (1) {
    /*현재 위치 청소*/
		map[x.r][x.c] = 1;


		if (!(map[x.r][x.c - 1] && map[x.r][x.c + 1] && map[x.r - 1][x.c] && map[x.r + 1][x.c]))
		{

			if (x.dir == 0)
			{
				x.dir = 3;
				if (map[x.r][x.c - 1] == 0)
				{
					x.c = x.c - 1; cnt++;
				}
			}
			else if (x.dir == 1) {
				x.dir = 0;
				if (map[x.r - 1][x.c] == 0)
				{
					x.r = x.r - 1; cnt++;
				}
			}
			else if (x.dir == 2) {
				x.dir = 1;
				if (map[x.r][x.c + 1] == 0)
				{
					x.c = x.c + 1; cnt++;
				}
			}
			else {//if(x.dir==3)
				x.dir = 2;
				if (map[x.r + 1][x.c] == 0)
				{
					x.r = x.r + 1; cnt++;
				}
			}
		} //if(!(map[x.r][x.c-1]*map[x.r][x.c+1]*map[x.r-1][x.c]*map[x.r+1][x.c]))

		else
		{
			if ((x.dir == 0 && x.r==N-2) || (x.dir == 1 && x.c==1) || (x.dir == 2 && x.r==1) || (x.dir == 3 && x.c==M-2))
			{
                cnt++;
				cout << cnt; break;
			}
			else if (x.dir == 0) {
				x.r++;
			}
			else if (x.dir == 1) {
				x.c--;
			}
			else if (x.dir == 2) {
				x.r--;
			}
			else {
				x.c++;
			}
		}
	}
}
