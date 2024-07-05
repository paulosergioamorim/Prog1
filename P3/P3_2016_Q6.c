#include <stdio.h>
#include <stdbool.h>

bool eBorda(int a, int b, int l, int h, int mapa[h][l]);

int main(int argc, char const *argv[])
{
    int h = 0;
    int l = 0;
    int i = 0;
    int j = 0;
    int qtdBorda = 0;
    scanf("%d %d", &l, &h);
    int mapa[h][l];
    for (i = 0; i < h; i++)
        for (j = 0; j < l; j++)
            scanf("%1d", &mapa[i][j]);
    for (i = 0; i < h; i++)
        for (j = 0; j < l; j++)
            if (eBorda(i, j, l, h, mapa))
                qtdBorda++;
    printf("%d\n", qtdBorda);
    return 0;
}

bool eBorda(int a, int b, int l, int h, int mapa[h][l])
{
    int i = 0;
    int j = 0;
    if (mapa[a][b] != 0)
        return false;
    for (i = a - 1; i <= a + 1; i++)
        for (j = b - 1; j <= b + 1; j++)
            if (!(i == a && j == b) && mapa[i][j] == 1)
                return true;
    return false;
}
