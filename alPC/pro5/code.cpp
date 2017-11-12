#include <iostream>
#include <string>
using namespace std;

char map[251][251];
int M, N;
void fill(int i, int j, char org_color, char color)
{
    map[i][j] = color;

    if (i>1 && map[i - 1][j] == org_color)
        fill(i - 1, j, org_color, color);
    if (i<N && map[i + 1][j] == org_color)
        fill(i + 1, j, org_color, color);
    if (j>1 && map[i][j - 1] == org_color)
        fill(i, j - 1, org_color, color);
    if (i<M && map[i][j + 1] == org_color)
        fill(i, j + 1, org_color, color);

}
int main()
{
    char order = 'l';
    while (order != 'X')
    {

        cin >> order;
        if (order == 'I')
        {
            cin >> M >> N;
            for (int i = 1; i <= M; i++)
            {
                for (int j = 1; j <= N; j++) map[j][i] = 'O';
            }
        }
        else if (order == 'C')
        {
            for (int i = 1; i <= M; i++)
            {
                for (int j = 1; j <= N; j++) map[j][i] = 'O';
            }
        }
        else if (order == 'L')
        {
            int X, Y;
            char C;
            cin >> X >> Y >> C;
            map[Y][X] = C;
        }
        else if (order == 'V')
        {
            int X, Y1, Y2;
            char C;
            cin >> X >> Y1 >> Y2 >> C;
            for (int i = Y1; i <= Y2; i++) { map[i][X] = C; }
        }
        else if (order == 'H')
        {
            int X1, X2, Y;
            char C;
            cin >> X1 >> X2 >> Y >> C;
            for (int i = X1; i <= X2; i++) { map[Y][i] = C; }
        }
        else if (order == 'K')
        {
            int X1, Y1, X2, Y2;
            char C;
            cin >> X1 >> Y1 >> X2 >> Y2 >> C;
            for (int i = X1; i <= X2; i++)
            {
                for (int j = Y1; j <= Y2; j++) map[j][i] = C;
            }
        }
        else if (order == 'F')
        {
            int X, Y;
            char C;
            cin >> X >> Y >> C;
            fill(Y, X, map[Y][X], C);
        }
        else if (order == 'S')
        {
            string s;
            cin >> s;
            cout << s << endl;
            for (int i = 1; i <= N; i++)
            {
                for (int j = 1; j <= M; j++) cout << map[i][j];
                cout << endl;
            }
        }
    }
    system("pause");
}
