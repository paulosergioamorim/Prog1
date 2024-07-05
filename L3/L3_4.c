#include <stdio.h>

void ImprimeMultiplos(int num, int max) {
    int i = 0;
    int hasMultiples = 0;
    for (i = 2 * num; i < max; i++)
    {
        if (i % num == 0) {
            printf("%d ", i);
            hasMultiples = 1;
        }
    }
    if (!hasMultiples)
        printf("*");
    printf("\n");
}

int EhPrimo(int num)
{
    int dividers = 0;
    int i = 0;
    for (i = 1; i <= num; i++)
        if (num % i == 0)
            dividers++;
    return dividers == 2 ? 1 : 0;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    
    scanf("%d %d", &n, &m);

    for (i = n + 1; i < m; i++)
        if (EhPrimo(i)) {
            printf("%d\n", i);
            ImprimeMultiplos(i, m);
        }

    return 0;
}
