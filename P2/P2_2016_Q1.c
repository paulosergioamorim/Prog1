#include <stdio.h>

int EhPar(int n);

int main(int argc, char const *argv[])
{
    int i = 0;
    int qtd = 0;
    int first = 0;
    int countPar = 0;
    int countImpar = 0;

    scanf("%d", &qtd);

    for (i = 0; i < qtd; i++)
    {
        int n = 0;
        scanf("%d", &n);
        if (i == 0)
            first = n;
        if (EhPar(n))
            countPar++;
        else
            countImpar++;
    }

    if (EhPar(first))
        printf("QTD PARES:%d", countPar);
    else
        printf("QTD IMPARES:%d", countImpar);

    return 0;
}

int EhPar(int n)
{
    return n % 2 == 0;
}