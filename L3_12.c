#include <stdio.h>

int somadosdigitos(int n);
void parimpar(int n);
void valorPrimo(int n);

int main(int argc, char const *argv[])
{
    int n = 0;
    scanf("%d", &n);

    while (n >= 10)
    {
        n = somadosdigitos(n);
        printf("%d ", n);
        parimpar(n);
        valorPrimo(n);
        printf("\n");
    }

    return 0;
}

int somadosdigitos(int n)
{
    int c = n;
    int s = 0;

    while (c != 0)
    {
        s += c % 10;
        c /= 10;
    }

    return s;
}

void parimpar(int n)
{
    printf(n % 2 == 0 ? "Par " : "Impar ");
}

void valorPrimo(int n)
{
    int i = 0;
    int d = 0;
    for (i = 1; i <= n; i++)
        if (n % i == 0)
            d++;

    printf(d == 2 ? "Primo" : "Nao e primo");
}
