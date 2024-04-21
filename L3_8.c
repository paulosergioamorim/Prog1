#include <stdio.h>
#include <stdlib.h>

int verificaPrimo(int n);
int transformaPrimo(int n);
int verificaNegativo(int n);

int main(int argc, char const *argv[])
{
    int l = 0;
    int c = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &l, &c);
    for (i = 0; i < l; i++)
    {
        printf("\t");
        for (j = 0; j < c; j++)
        {
            int n = 0;
            scanf("%d", &n);
            printf("%d ", transformaPrimo(n));
        }
        printf("\n");
    }

    return 0;
}

int verificaPrimo(int n)
{
    int d = 0;
    int i = 0;

    for (i = 1; i <= n; i++)
        if (n % i == 0)
            d++;

    return d == 2;
}

int transformaPrimo(int n)
{
    int c = n;
    
    while (!verificaPrimo(abs(c)))
        c += verificaNegativo(c) ? -1 : 1;

    return -32000 <= c && c <= 32000 ? c : n;
}

int verificaNegativo(int n)
{
    return n < 0;
}
