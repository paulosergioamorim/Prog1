#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;

    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++)
    {
        int d = i % 10;
        int c = (i - d) / 10 % 10;
        int b = (i - d - 10 * c) / 100 % 10;
        int a = (i - d - 10 * c - 100 * b) / 1000 % 10;
        int ef = 10 * a + b + 10 * c + d;
        if (ef * ef == i)
            printf("%d\n", i);
    }

    return 0;
}
