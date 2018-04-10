#include <stdio.h>

#include <windows.h>

#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define SPACE 32

#define MAP_X 39

#define MAP_Y 24

#define ESC 27

#define U1 1

#define U2 2

typedef struct XY{

	int x;

	int y;

}xy;

gotoxy(int x, int y)

{

	COORD pos = {x, y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

void initGame()

{

	int i = 0, k = 0;

	for(i = 0 ; i < MAP_Y ; i ++)

	{

		for(k = 0 ; k < MAP_X ; k ++)

		{

			if(i == 0)

			{

				if(k == 0)

					printf("┌");

				else if(k+1 == MAP_X)

					printf("┐");

				else

					printf("┬");

			}

			else if(i+1 < MAP_Y)

			{

				if(k == 0)

					printf("├");

				else if(k+1 == MAP_X)

					printf("┤");
a#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define UP 72
#define LEFT 75
#define DOWN 80
#define RIGHT 77
#define SPACE 32
#define ENTER 13
#define X 0
#define Y 1

#define W_SIZE 15 // 오목판 가로 사이즈
#define H_SIZE 15 // 오목판 세로 사이즈

char turn = 0,
	bwin = 0,
	wwin = 0;
int chk = 0;
int board[W_SIZE+2][H_SIZE+2] = {0};
int cursor[2] = {W_SIZE / 2, H_SIZE / 2};

void draw_board(void); // 오목칸 그리기 함수
void winchk(void); // 승리 판정 함수
void move_cursor(void); // 키 입력 - 커서 이동
void reset_quit(void); // 키 입력 - 커서 이동, 재시작, 종료
void clear_board(void); // 초기화

int main(void)
{
	while(1)
	{
		if(chk == 1) clear_board();
		draw_board();
		winchk();
		if(bwin > 0 || wwin > 0) // 판정
		{
			while(chk == 0)
			{
				cursor[X] = 99;
				draw_board();
				if(wwin == 99 && bwin == 99) printf("　◎ 승부가 나지 않았습니다.\n\n");

				else if(turn == 1) printf("　○ 흑의 승리! ○\n\n");
				else printf("　● 백의 승리! ●\n\n");
				printf("　(다시 시작 : r, R)\n　(종료 　　 : q, Q)\n");

				reset_quit();
				if(chk > 0) break;
			}
			clear_board();
			draw_board();
		}
		if(chk == 2) break; // 종료 시 반복문 밖으로 탈출
		chk = 0;

		if(turn == 0) printf("　○ 흑의 차례 ○\n\n");
		else printf("　● 백의 차례 ●\n\n");
		printf("　(다시 시작 : r, R)\n　(종료 　　 : q, Q)\n");
		move_cursor();
	}
	return 0;
}

/* 칸 사이에 공백이 넓은 오목 칸
void draw_board(void)
{
	int bx, by, i;

	system("cls");
	for(by = 1 ; by <= H_SIZE ; by++)
	{
		printf("　");
		for(bx = 1 ; bx <= W_SIZE ; bx++)
		{
			if(cursor[X] == bx && cursor[Y] == by) // 커서 표시
			{
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("▒");
							else printf("─▒");
							break;
						case 1 :
							if(bx == 1) printf("□");
							else printf("─□");
							break;
						case 2 :
							if(bx == 1) printf("■");
							else printf("─■");
							break;
					}
				} else if(by == H_SIZE) {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("▒");
							else printf("━▒");
							break;
						case 1 :
							if(bx == 1) printf("□");
							else printf("━□");
							break;
						case 2 :
							if(bx == 1) printf("■");
							else printf("━■");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("▒");
							else printf("━▒");
							break;
						case 1 :
							if(bx == 1) printf("□");
							else printf("━□");
							break;
						case 2 :
							if(bx == 1) printf("■");
							else printf("━■");
							break;
					}
				}
			} else {
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) // 오목알 표시
					{
						case 0 :
							if(bx == 1) printf("┠");
							else if(bx == W_SIZE)  printf("─┨");
							else printf("─┼");
							break;
						case 1 :
							if(bx == 1) printf("○");
							else printf("─○");
							break;
						case 2 :
							if(bx == 1) printf("●");
							else printf("─●");
							break;
					}
				} else if(by == H_SIZE) {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("┗");
							else if(bx == W_SIZE)  printf("━┛");
							else printf("━┷");
							break;
						case 1 :
							if(bx == 1) printf("○");
							else printf("━○");
							break;
						case 2 :
							if(bx == 1) printf("●");
							else printf("━●");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("┏");
							else if(bx == W_SIZE)  printf("━┓");
							else printf("━┯");
							break;
						case 1 :
							if(bx == 1) printf("○");
							else printf("━○");
							break;
						case 2 :
							if(bx == 1) printf("●");
							else printf("━●");
							break;
					}
				}
			}
		}
		printf("\n");
		if(by != H_SIZE)
		{
			printf("　┃");
			for(i = 0 ; i < W_SIZE-2 ; i++) printf("　│");
			printf("　┃\n");
		}
	}

}
*/

/* 칸 사이의 공백이 없는 오목판 */
void draw_board(void)
{
	int bx, by, i;

	system("cls");
	for(by = 1 ; by <= H_SIZE ; by++)
	{
		printf("　");
		for(bx = 1 ; bx <= W_SIZE ; bx++)
		{
			if(cursor[X] == bx && cursor[Y] == by) // 커서 표시
			{
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx])
					{
						case 0 :
							printf("▒");
							break;
						case 1 :
							printf("□");
							break;
						case 2 :
							printf("■");
							break;
					}
				} else if(by == H_SIZE) {
					switch(board[by][bx])
					{
						case 0 :
							printf("▒");
							break;
						case 1 :
							printf("□");
							break;
						case 2 :
							printf("■");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case 0 :
							printf("▒");
							break;
						case 1 :
							printf("□");
							break;
						case 2 :
							printf("■");
							break;
					}
				}
			} else {
				if(by != 1 && by != H_SIZE)
				{
					switch(board[by][bx]) // 오목알 표시
					{
						case 0 :
							if(bx == 1) printf("┠");
							else if(bx == W_SIZE)  printf("┨");
							else printf("┼");
							break;
						case 1 :
							printf("○");
							break;
						case 2 :
							printf("●");
							break;
					}
				} else if(by == H_SIZE) {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("┗");
							else if(bx == W_SIZE)  printf("┛");
							else printf("┷");
							break;
						case 1 :
							printf("○");
							break;
						case 2 :
							printf("●");
							break;
					}
				} else {
					switch(board[by][bx])
					{
						case 0 :
							if(bx == 1) printf("┏");
							else if(bx == W_SIZE)  printf("┓");
							else printf("┯");
							break;
						case 1 :
							printf("○");
							break;
						case 2 :
							printf("●");
							break;
					}
				}
			}
		}
		printf("\n");
	}
}
//*/

void winchk(void)
{
	int fullcount = 0;
	int i, j;

	bwin = 0;
	wwin = 0;

	for(j = 1 ; j < H_SIZE+1 ; j++) // 오목판 꽉참
	{
		for(i = 1 ; i < W_SIZE+1 ; i++)
		{
			if(board[j][i] != 0) fullcount++;
		}
	}

	if(fullcount == W_SIZE * H_SIZE)
	{
		bwin = 99;
		wwin = 99;
	}

	for(j = 1 ; j < H_SIZE+1 ; j++) // ㅡ 모양 오목
	{
		for(i = 1 ; i < W_SIZE-3 ; i++)
		{
			if(board[j][i] == 1
			&& board[j][i+1] == 1
			&& board[j][i+2] == 1
			&& board[j][i+3] == 1
			&& board[j][i+4] == 1

			&& board[j][i-1] != 1
			&& board[j][i+5] != 1) bwin = 1;

			else if(board[j][i] == 2
				 && board[j][i+1] == 2
				 && board[j][i+2] == 2
				 && board[j][i+3] == 2
				 && board[j][i+4] == 2

				 && board[j][i-1] != 2
				 && board[j][i+5] != 2) wwin = 1;
		}
	}

	for(i = 1 ; i < W_SIZE+1 ; i++) // ㅣ 모양 오목
	{
		for(j = 1 ; j < H_SIZE-3 ; j++)
		{
			if(board[j][i] == 1
			&& board[j+1][i] == 1
			&& board[j+2][i] == 1
			&& board[j+3][i] == 1
			&& board[j+4][i] == 1

			&& board[j-1][i] != 1
			&& board[j+5][i] != 1) bwin = 1;

			else if(board[j][i] == 2
				 && board[j+1][i] == 2
				 && board[j+2][i] == 2
				 && board[j+3][i] == 2
				 && board[j+4][i] == 2

				 && board[j-1][i] != 2
				 && board[j+5][i] != 2) wwin = 1;
		}
	}

	for(j = 1 ; j < H_SIZE-3 ; j++) // ＼ 모양 오목
	{
		for(i = 1 ; i < W_SIZE-3 ; i++)
		{
			if(board[j][i] == 1
			&& board[j+1][i+1] == 1
			&& board[j+2][i+2] == 1
			&& board[j+3][i+3] == 1
			&& board[j+4][i+4] == 1

			&& board[j-1][i-1] != 1
			&& board[j+5][i+5] != 1) bwin = 1;

			else if(board[j][i] == 2
				 && board[j+1][i+1] == 2
				 && board[j+2][i+2] == 2
				 && board[j+3][i+3] == 2
				 && board[j+4][i+4] == 2

				 && board[j-1][i-1] != 2
				 && board[j+5][i+5] != 2) wwin = 1;
		}
	}

	for(i = 1 ; i < W_SIZE-3 ; i++) // / 모양 오목
	{
		for(j = 5 ; j < H_SIZE+1 ; j++)
		{
			if(board[j][i] == 1
			&& board[j-1][i+1] == 1
			&& board[j-2][i+2] == 1
			&& board[j-3][i+3] == 1
			&& board[j-4][i+4] == 1

			&& board[j-5][i+5] != 1
			&& board[j+1][i-1] != 1) bwin = 1;

			else if(board[j][i] == 2
				 && board[j-1][i+1] == 2
				 && board[j-2][i+2] == 2
				 && board[j-3][i+3] == 2
				 && board[j-4][i+4] == 2

				 && board[j-5][i+5] != 2
				 && board[j+1][i-1] != 2) wwin = 1;
		}
	}
}

void move_cursor(void)
{
	char ch;

	ch = getch();
	switch(ch) // 화살표키 인식
	{
	case UP : // 상
		if(cursor[Y] != 1) cursor[Y]--;
		else cursor[Y] = H_SIZE;
		break;
	case LEFT : // 좌
		if(cursor[X] != 1) cursor[X]--;
		else cursor[X] = W_SIZE;
		break;
	case RIGHT : // 우
		if(cursor[X] != W_SIZE) cursor[X]++;
		else cursor[X] = 1;
		break;
	case DOWN : // 하
		if(cursor[Y] != H_SIZE) cursor[Y]++;
		else cursor[Y] = 1;
		break;
	case ENTER :
		if(turn == 0 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if(turn == 1 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case SPACE :
		if(turn == 0 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 1;
			turn = 1;
		}
		else if(turn == 1 && board[cursor[Y]][cursor[X]] == 0)
		{
			board[cursor[Y]][cursor[X]] = 2;
			turn = 0;
		}
		break;
	case 'r':
		chk = 1;
		break;
	case 'R':
		chk = 1;
		break;
	case 'q' :
		chk = 2;
		break;
	case 'Q' :
		chk = 2;
		break;
	default :
		chk = 0;
		break;
	}
}

void reset_quit(void)
{
	char ch;

	ch = getch();
	switch(ch) // 재시작, 종료 여부
	{
	case 'r':
		chk = 1;
		break;
	case 'R':
		chk = 1;
		break;
	case 'q' :
		chk = 2;
		break;
	case 'Q' :
		chk = 2;
		break;
	default :
		chk = 0;
		break;
	}
}

void clear_board(void)
{
	int i, j;

	turn = 0;
	wwin = 0;
	bwin = 0;
	cursor[X] = W_SIZE / 2;
	cursor[Y] = H_SIZE / 2;
	for(i = 1 ; i < W_SIZE ; i++)
	{
		for(j = 1 ; j < H_SIZE ; j++) board[j][i] = 0;
	}
}
				else

					printf("┼");

			}

			else

			{

				if(k == 0)

					printf("└");

				else if(k+1 == MAP_X)

					printf("┘");

				else

					printf("┴");

			}

		}

		printf("\n");

	}

}

int searchStone(xy hd, int GMap[MAP_Y][MAP_X], int flag, int p, int sw)

{

	if(GMap[hd.y][hd.x] != flag) return 0;

	if(p == 0) // 위 아래 탐색

	{

		hd.y += sw;

	}

	else if(p == 1) // 좌 우 탐색

	{

		hd.x += sw;

	}

	else if(p == 2) // 왼쪽 위 -> 오른쪽 아래

	{

		hd.x += sw;

		hd.y += sw;

	}

	else // 오른쪽 위 -> 왼쪽 아래

	{

		hd.x += sw;

		hd.y -= sw;

	}

	return 1 + searchStone(hd, GMap, flag, p, sw);

}

void checkStone(xy hd, int GMap[MAP_Y][MAP_X], int turn)

{

	int i = 0, countStone = 0;

	for(i = 0 ; i < 4 ; i ++)

	{

		countStone = 0;

		countStone += searchStone(hd, GMap, turn, i, 1);

		countStone += searchStone(hd, GMap, turn, i, -1);

		if(countStone == 6)

		{

			gotoxy(0,MAP_Y);

			if(turn == U1)

				printf("사용자 1");

			else

				printf("사용자 2");

			printf("님이 승리하셨습니다.!");

			getch();

			exit(1);

		}

	}

}

void startGame(int GMap[MAP_Y][MAP_X])

{

	char ip = '\0';

	int turn = U1;

	xy hd = {MAP_X/2, MAP_Y/2};

	while(1)

	{

		if(kbhit())

		{

			ip = getch();

			switch(ip)

			{

			case LEFT:

				if(hd.x > 0)

					hd.x -= 1;

				break;

			case RIGHT:

				if(hd.x < MAP_X-1)

					hd.x += 1;

				break;

			case UP:

				if(hd.y > 0)

					hd.y -= 1;

				break;

			case DOWN:

				if(hd.y < MAP_Y-1)

					hd.y += 1;

				break;

			case SPACE:

				if(GMap[hd.y][hd.x] == 0)

				{

					gotoxy(hd.x*2, hd.y);



					if(turn == U1)

					{

						GMap[hd.y][hd.x] = U1;

						printf("●");

						checkStone(hd, GMap, turn);

						turn = U2;

					}

					else

					{

						GMap[hd.y][hd.x] = U2;

						printf("○");

						checkStone(hd, GMap, turn);

						turn = U1;

					}

				}

				break;

			case ESC:

				exit(1);

				break;

			}

			gotoxy(hd.x*2, hd.y);

		}

	}

}

int main()

{

	int GMap[MAP_Y][MAP_X]={0,};

	printf("> 2인용 오목게임\n");

	printf("> KEY - 방향키, 스페이스\n");

	printf("      - 종료(ESC)\n\n");

	printf("게임을 시작하시려면 아무키나 누르세요");

	getch();

	system("cls");

	initGame();

	startGame(GMap);

}
