#include <stdio.h>

char Codifica(char letra, int n);
char Decodifica(char letra, int n);
int EhLetra(char c);
int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);

int main(int argc, char const *argv[])
{
    int mode = 0;
    int key = 0;
    char c = '\0';

    scanf("%d %d ", &mode, &key);
    key %= 26;
    while (scanf("%c", &c))
    {
        if (mode == 1)
            printf("%c", Codifica(c, key));
        else if (mode == 2)
            printf("%c", Decodifica(c, key));
        else
        {
            printf("Operacao invalida.");
            return 0;
        }
        if (c == '.')
            return 0;
    }
}

char Codifica(char letra, int n)
{
    if (!EhLetra(letra))
        return letra;

    if (EhLetraMinuscula(letra))
    {
        letra -= 32;
        letra += n;
        if (letra > 'Z')
            letra -= 26;
        return letra + 32;
    }

    letra += 2 * n;
    if (letra > 'Z')
        letra -= 26;

    return letra;
}

char Decodifica(char letra, int n)
{
    if (!EhLetra(letra))
        return letra;

    if (EhLetraMinuscula(letra))
    {
        letra -= 32;
        letra -= n;
        if (letra < 'A')
            letra += 26;
        return letra + 32;
    }

    letra -= 2 * n;
    if (letra < 'A')
        letra += 26;

    return letra;
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
