#include <stdio.h>

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
        if (EhPrimo(i))
            printf("%d ", i);

    return 0;
}
