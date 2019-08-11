#include <iostream>
#include <string>
using namespace std;

const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

char map[5][5];
bool alphabet[26];
bool flag;
void input(int & N);
void run(int & N);
bool str_chk(string & str);
void str_find(string & str, int y, int x, int idx);

int main()
{
	int C, N;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		input(N);
		run(N);
	}



	return 0;
}

void input(int & N)
{
	for (int i = 0; i< 5; i++)
	{
		cin >> map[i];
		for (int j = 0; j < 5; j++)
		{
			alphabet[map[i][j] - 'A'] = true;
		}
	}

	cin >> N;
	return;
}

void run(int & N)
{
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		if (!str_chk(str))
		{
			cout << str << " NO" << endl;
			continue;
		}

		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (map[j][k] == str[0])
				{
					flag = 0;
					str_find(str, j, k, 1);

				}
				if (flag == true) break;
			}
			if (flag == true) break;
		}
		if (flag == true)
		{
			cout << str << " YES" << endl;
			flag = false;
		}
	}

	return;
}

bool str_chk(string & str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!alphabet[str[i] - 'A']) return false;
	}
	return true;
}

 void str_find(string & str, int y, int x, int idx)
{ // dfs
	 if (idx == str.size()) {
		 flag = true;
		 return;
	 }
	for (int i = 0; i < 8; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx > 4 || ny < 0 || ny > 4) continue;
		if (map[ny][nx] == str[idx + 1])
		{
			str_find(str, ny, nx, idx + 1);
		}
	}
	return;
}
