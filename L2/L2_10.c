#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &a, &b);

    for (i = a; i <= b; i++)
        for (j = 1; j <= 10; j++)
            printf("%d x %d = %d\n", i, j, i * j);

    return 0;
}
