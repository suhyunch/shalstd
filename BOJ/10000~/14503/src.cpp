#include <iostream>
using namespace std;
#define north 0
#define east 1
#define south 2
#define west 3

struct robot {
	int y;
	int x;
	int dir;
};

int dy[4]={0, -1, 0, 1};
int dx[4]={-1, 0, 1, 0};
int ry[4]={1, 0, -1, 0};
int rx[4]={0, -1, 0, 1};
int main()
{
	int N, M;
	cin >> N >> M;

	int map[50][50] ;
  /*initialization*/
  for(int i=0; i<50; i++) for(int j=0; j<50; j++) map[i][j]=1;

	robot R;
	cin >> R.y>> R.x >> R.dir;

	int cnt = 0;
	int checker=0;
	for (int i = 0; i<N; i++) for (int j = 0; j<M; j++) cin >> map[i][j];

	while (1) {
    /*현재 위치 청소*/
		if(map[R.y][R.x]==0) {
			checker=0;
			map[R.y][R.x] = 2;
			cnt++;
		}

		//왼방향 탐색
		if(map[R.y+dy[R.dir]][R.x+dx[R.dir]]==0) {
			R.y=R.y+dy[R.dir];
			R.x=R.x+dx[R.dir];
			R.dir=(R.dir+3)%4;
		}
		else if(checker==4){
			int r_y=R.y+ry[R.dir];
			int r_x=R.x+rx[R.dir];
			if(map[r_y][r_x]==1){
				break;
			}
			else {
				switch(R.dir){
					case north :{
						R.y++;
						break;
					}
					case east :{
						R.x--;
						break;
					}
					case south :{
						R.y--;
						break;
					}
					case west :{
						R.x++;
						break;
					}
				}
				checker=0;
			}
		}
		else {
			R.dir=(R.dir+3)%4;
			checker++;
		}
	}

	cout << cnt;
}
