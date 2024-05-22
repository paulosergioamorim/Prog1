#include <stdio.h>

int EhDigito(char c);
char LeProximoChar(char terminador);
void ImprimePorExtenso(char digito);

int main(int argc, char const *argv[])
{
    char terminador = 0;
    char c = 0;
    scanf("%c ", &terminador);
    while (c = LeProximoChar(terminador))
    {
        if (EhDigito(c))
        {
            char digito = c;
            if (!(c = LeProximoChar(terminador)))
            {
                ImprimePorExtenso(digito);
                break;
            }
            else if (EhDigito(c))
            {
                printf("%c", digito);
                printf("%c", c);
                while (EhDigito(c) && (c = LeProximoChar(terminador)))
                    printf("%c", c);
            }
            else
            {
                ImprimePorExtenso(digito);
                printf("%c", c);
            }
        }
        else
            printf("%c", c);
    }
    return 0;
}

int EhDigito(char c)
{
    return '0' <= c && c <= '9';
}

char LeProximoChar(char terminador)
{
    char c = 0;
    scanf("%c", &c);
    if (c == terminador)
        return 0;
    return c;
}

void ImprimePorExtenso(char digito)
{
    switch (digito - '0')
    {
    case 0:
        printf("zero");
        break;
    case 1:
        printf("um");
        break;
    case 2:
        printf("dois");
        break;
    case 3:
        printf("tres");
        break;
    case 4:
        printf("quatro");
        break;
    case 5:
        printf("cinco");
        break;
    case 6:
        printf("seis");
        break;
    case 7:
        printf("sete");
        break;
    case 8:
        printf("oito");
        break;
    case 9:
        printf("nove");
        break;
    }
}
