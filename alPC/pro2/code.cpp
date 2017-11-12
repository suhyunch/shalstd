#include <stdio.h>

int main()
{
	FILE *fp;
	int N, M, cnt = 0;//N행의 갯수, M열의 갯수;
	int Fcnt = 0;
	char map[102][102] = { 0 };
	fp = fopen("D:\atom_coding\al_pc\pro2\input.txt", "r");
	fscanf(fp, "%d %d", &N, &M);

	while (!((N == 0) && (M == 0)))
	{
		printf("%d %d \n", N, M);
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
			{
				fscanf(fp, "%s", &map[i][j]);
//fscanf는 문자를 받을 때 주소연산자 & 필요
//scanf는 문자를 받을 때 &필요없음
				//printf("map[%d][%d] %s \n", i, j, &map[i][j]);
			}

		Fcnt++;
		//printf("Field #%d : \n", Fcnt);
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				cnt = 0;
				if (map[i][j] == '*') printf("* ");
				else //if (map[i][j] != '*')
				{
					if (map[i - 1][j - 1] == '*') cnt++;
					if (map[i - 1][j] == '*') cnt++;
					if (map[i - 1][j + 1] == '*') cnt++;
					if (map[i][j - 1] == '*') cnt++;
					if (map[i][j + 1] == '*') cnt++;
					if (map[i + 1][j - 1] == '*') cnt++;
					if (map[i + 1][j] == '*') cnt++;
					if (map[i + 1][j + 1] == '*') cnt++;

					printf("%d ", cnt);

				}

			}printf("\n");
		}fscanf(fp, "%d %d", &N, &M); printf("\n");
	}
	fclose(fp);//파일 닫음
	return 0;
}
