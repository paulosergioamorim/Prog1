#include <stdio.h>

int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int CalculaValorPalavra();
int EhPrimo(int n);
int ProximoPrimo(int n);

int main(int argc, char const *argv[])
{
    while (1)
    {
        int n = CalculaValorPalavra();
        if (n == -1)
            break;
        else if (EhPrimo(n))
            printf("E primo\n");
        else
            printf("Nao e primo %d\n", ProximoPrimo(n));
    }

    return 0;
}

int EhLetra(char c)
{
    return EhLetraMaiuscula(c) || EhLetraMinuscula(c);
}

int EhLetraMinuscula(char c)
{
    return 'a' <= c && c <= 'z';
}

int EhLetraMaiuscula(char c)
{
    return 'A' <= c && c <= 'Z';
}

int CalculaValorPalavra()
{
    int value = 0;
    char letter = '\0';

    while (1)
    {
        scanf("%c", &letter);

        if (!EhLetra(letter))
        {
            if (letter == '\n')
                return value;
            if (letter == '\0')
                return -1;
            continue;
        }
        else if (EhLetraMaiuscula(letter))
            value += letter - ('A' - 27);
        else if (EhLetraMinuscula(letter))
            value += letter - ('a' - 1);
    }
}

int EhPrimo(int n)
{
    int i = 0;
    int d = 0;

    for (i = 1; i <= n; i++)
        if (n % i == 0)
            d++;

    return d == 2;
}

int ProximoPrimo(int n)
{
    int i = 0;

    for (i = n + 1; 1; i++)
        if (EhPrimo(i))
            return i;
}
