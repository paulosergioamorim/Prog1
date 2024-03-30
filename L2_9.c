#include <stdio.h>

int is_prime(int n)
{
    int i = 0;
    int div = 0;
    for (i = 1; i <= n; i++)
        if (n % i == 0)
            div++;
    return div == 2 ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &n, &m);
    for (i = n + 1; i < m; i++)
        if (is_prime(i))
        {
            printf("%d\n", i);
            if (m <= 2 * i)
            {
                printf("*\n");
                continue;
            }

            for (j = 2 * i; j < m; j += i)
                printf("%d ", j);
            printf("\n");
        }

    return 0;
}
