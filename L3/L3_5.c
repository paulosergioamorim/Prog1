#include <stdio.h>

int Propriedade(int num)
{
    int d = num % 10;
    int c = (num - d) / 10 % 10;
    int b = (num - d - 10 * c) / 100 % 10;
    int a = (num - d - 10 * c - 100 * b) / 1000 % 10;
    int ef = 10 * a + b + 10 * c + d;
    return ef * ef == num;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;

    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++)
        if (Propriedade(i))
            printf("%d\n", i);

    return 0;
}
