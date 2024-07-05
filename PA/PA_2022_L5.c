#include <stdio.h>
#include <stdlib.h>

int move_x_to(int x, int y, int a, int l, int c, int vec[l][c]);
int move_y_to(int x, int y, int b, int l, int c, int vec[l][c]);
void init_vec(int l, int c, int vec[l][c]);
void print_vec(int l, int c, int vec[l][c]);

int main(int argc, char const *argv[])
{
    int l = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
    scanf("%d %d", &l, &c);
    int vec[l][c];
    init_vec(l, c, vec);
    do
    {
        scanf("%d %d\n", &a, &b);
        if (abs(a - x) <= abs(b - y))
        {
            x = move_x_to(x, y, a, l, c, vec);
            y = move_y_to(x, y, b, l, c, vec);
        }
        else
        {
            y = move_y_to(x, y, b, l, c, vec);
            x = move_x_to(x, y, a, l, c, vec);
        }
    } while (a != 0 || b != 0);
    print_vec(l, c, vec);
    return 0;
}

int move_x_to(int x, int y, int a, int l, int c, int vec[l][c])
{
    int move = x < a ? 1 : -1;
    while (x != a)
    {
        x += move;
        vec[x][y] = 1;
    }
    return x;
}

int move_y_to(int x, int y, int b, int l, int c, int vec[l][c])
{
    int move = y < b ? 1 : -1;
    while (y != b)
    {
        y += move;
        vec[x][y] = 1;
    }
    return y;
}

void init_vec(int l, int c, int vec[l][c])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            vec[i][j] = 0;
    vec[0][0] = 1;
}

void print_vec(int l, int c, int vec[l][c])
{
    int i = 0;
    int j = 0;
    for (j = 0; j < c; j++)
    {
        for (i = 0; i < l; i++)
            printf("%d ", vec[i][j]);
        printf("\n");
    }
}
