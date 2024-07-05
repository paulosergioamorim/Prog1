#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t = 0;
    int m = 0;
    int i = 0;

    scanf("%d %d", &t, &m);

    for (i = t; i < m; i += 2)
    {
        int j = 0;

        for (j = 0; j < (m - i) / 2; j++)
            printf("_");

        for (j = 0; j < i; j++)
            printf("$");

        for (j = 0; j < (m - i) / 2; j++)
            printf("_");

        printf("\n");
    }

    for (i = m; i >= 1; i -= 2)
    {
        int k = 0;

        for (k = 0; k < (m - i) / 2; k++)
            printf("_");

        for (k = 0; k < i; k++)
            printf("$");

        for (k = 0; k < (m - i) / 2; k++)
            printf("_");

        printf("\n");
    }

    return 0;
}
