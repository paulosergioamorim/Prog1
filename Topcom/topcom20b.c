#include <stdio.h>
#define FRENTE 1
#define TRAS 2
#define ESQUERDA 3
#define DIREITA 4

int main(int argc, char const *argv[])
{
    int l = 0;
    int c = 0;
    int x = 0;
    int y = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d\n%d %d", &l, &c, &x, &y);
    int vec[l][c];
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            vec[i][j] = 0;
    vec[x][y] = 1;
    while (1)
    {
        scanf("%d", &m);
        if (m == 0)
            break;
        switch (m)
        {
        case FRENTE:
            if (x == 0)
                x = l - 1;
            else
                x--;
            break;
        case TRAS:
            if (x == l - 1)
                x = 0;
            else
                x++;
            break;
        case ESQUERDA:
            if (y == 0)
                y = c - 1;
            else
                y--;
            break;
        case DIREITA:
            if (y == c - 1)
                y = 0;
            else
                y++;
            break;
        }
        vec[x][y] = 1;
    }
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", vec[i][j]);
        printf("\n");
    }
    return 0;
}
