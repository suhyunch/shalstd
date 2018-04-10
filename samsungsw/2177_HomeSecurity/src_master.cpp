#define _CRT_SECURE_NO_WARNINGS
#if 1
#include <stdio.h>
#define ABS(x,y) ((((x)-(y)) > 0) ? ((x)-(y)) : ((y)-(x)))

int N, M, H, max;
int home[400][2];
int cost[40];
int count[40];

void cal_cost(void)
{
    int i;
    for (i = 1; i < 40; i++)
        cost[i] = i*i + (i - 1)*(i - 1);
}

void input(void)
{
    int i, j, x;
    scanf("%d %d", &N, &M);
    H = max = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &x);
            if (x)
            {
                home[H][0] = i;
                home[H][1] = j;
                H++;
            }
        }
    }
}

void clear(void)
{
    int i;
    for (i = 0; i < 40; i++)
        count[i] = 0;
}

void calculate(int x, int y)
{
    int i, sum = 0;
    for (i = 0; i < H; i++)
    {
        count[ABS(home[i][0], x) + ABS(home[i][1], y)]++;
    }
    for (i = 0; i < 39; i++)
    {
        sum += count[i];
        if (sum > max && M * sum >= cost[i + 1])
            max = sum;
    }
}

int main(void) {
    int t, T, i, j;
    scanf("%d", &T);
    cal_cost();
    for (t = 1; t <= T; t++)
    {
        input();
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
            {
                clear();
                calculate(i, j);
            }
        printf("#%d %d\n", t, max);
    }
    return 0;
}
#endif
