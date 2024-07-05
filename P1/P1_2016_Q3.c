#include <stdio.h>

int EhDigito(char c);
int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int EhVogal(char c);
int EhConsoante(char c);

int main(int argc, char const *argv[])
{
    char c1 = 0;
    char c2 = 0;
    char c3 = 0;
    char c4 = 0;

    scanf("%c%c%c%c", &c1, &c2, &c3, &c4);

    if (!EhLetraMaiuscula(c1))
    {
        printf("Invalido");
        return 0;
    }
    if (!EhDigito(c2))
    {
        printf("Invalido");
        return 0;
    }
    if (!EhVogal(c3))
    {
        printf("Invalido");
        return 0;
    }
    else if (EhLetraMinuscula(c3))
        c3 -= 32;
    if (!EhLetraMinuscula(c4) || !EhConsoante(c4))
    {
        printf("Invalido");
        return 0;
    }
    else
        c4 -= 32;

    printf("%c%c%c%c", c1, c2, c3, c4);

    return 0;
}

int EhDigito(char c)
{
    return '0' <= c && c <= '9';
}

int EhLetra(char c)
{
    return EhLetraMaiuscula(c) || EhLetraMinuscula(c);
}

int EhLetraMaiuscula(char c)
{
    return 'A' <= c && c <= 'Z';
}

int EhLetraMinuscula(char c)
{
    return 'a' <= c && c <= 'z';
}

int EhVogal(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int EhConsoante(char c)
{
    if (!EhLetra(c))
        return 0;

    return !EhVogal(c);
}
