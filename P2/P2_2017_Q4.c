#include <stdio.h>

int EhLetra(char c);
int EhVogal(char c);
int ReconheceSimbolo(char c);

int main(int argc, char const *argv[])
{
    int letras = 0;
    int vogais = 0;
    int consoantes = 0;
    char c = 0;

    while (1)
    {
        scanf("%c", &c);

        if (c == '.')
        {
            printf(".");
            return 0;
        }

        switch (ReconheceSimbolo(c))
        {
        case -1:
            printf("*ERRO*");
            break;
        case 0:
            break;
        case 1:
            printf("*L:%d V:%d C:%d*", letras, vogais, consoantes);
            letras = 0;
            vogais = 0;
            consoantes = 0;
            break;
        case 2:
            printf("*V:%d*", vogais);
            vogais = 0;
            break;
        case 3:
            printf("*C:%d*", consoantes);
            consoantes = 0;
            break;
        }

        if (EhLetra(c))
        {
            letras++;
            if (EhVogal(c))
                vogais++;
            else
                consoantes++;
            printf("%c", c);
            continue;
        }
    }
}

int EhLetra(char c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int EhVogal(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int ReconheceSimbolo(char c)
{
    int value = 0;
    char lastChar = 0;

    if (c != '*')
        return 0;

    scanf("%c", &c);

    if (c == '*')
        return -1;

    scanf("%c", &lastChar);

    if (lastChar != '*')
    {
        scanf("%*[^*]%c", &lastChar);
        return -1;
    }
    if (c == '1')
        return 1;
    if (c == '2')
        return 2;
    if (c == '3')
        return 3;
    return -1;
}
