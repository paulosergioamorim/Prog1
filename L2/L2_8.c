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
    scanf("%d %d", &n, &m);
    printf("RESP:");
    for (i = n + 1; i < m; i++)
        if (is_prime(i))
            printf("%d ", i);

    return 0;
}
