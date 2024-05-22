#include <stdio.h>

int EhLetraMaiuscula(char c);
int EhLetraMinuscula(char c);
int EhNumero(char c);
int AnalisaSenha();

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);

    int maiorInvalidasCount = 0;
    int maiorInvalidasGrupo = 0;
    int maiorFracasCount = 0;
    int maiorFracasGrupo = 0;
    int maiorFortesCount = 0;
    int maiorFortesGrupo = 0;

    for (i = 1; i <= n; i++)
    {
        int invalidasCount = 0;
        int fracasCount = 0;
        int fortesCount = 0;

        printf("GRUPO %d\n", i);

        while (1)
        {
            int id = 0;
            scanf("%d", &id);

            if (id == -1)
                break;

            int analise = AnalisaSenha();
            if (analise == 0)
            {
                invalidasCount++;
                printf("INVALIDA\n");
            }
            else if (analise == 1)
            {
                fracasCount++;
                printf("FRACA\n");
            }
            else
            {
                fortesCount++;
                printf("FORTE\n");
            }
        }

        if (invalidasCount > maiorInvalidasCount)
        {
            maiorInvalidasCount = invalidasCount;
            maiorInvalidasGrupo = i;
        }
        if (fracasCount > maiorFracasCount)
        {
            maiorFracasCount = fracasCount;
            maiorFracasGrupo = i;
        }
        if (fortesCount > maiorFortesCount)
        {
            maiorFortesCount = fortesCount;
            maiorFortesGrupo = i;
        }

        printf("\n");
    }

    printf("FORTES: GRUPO(%d) QTD(%d)\n", maiorFortesGrupo, maiorFortesCount);
    printf("FRACAS: GRUPO(%d) QTD(%d)\n", maiorFracasGrupo, maiorFracasCount);
    printf("INVALIDAS: GRUPO(%d) QTD(%d)\n", maiorInvalidasGrupo, maiorInvalidasCount);

    return 0;
}

int EhLetraMaiuscula(char c)
{
    return 'A' <= c && c <= 'Z';
}

int EhLetraMinuscula(char c)
{
    return 'a' <= c && c <= 'z';
}

int EhNumero(char c)
{
    return '0' <= c && c <= '9';
}

int AnalisaSenha()
{
    char c = 0;
    int upperCount = 0;
    int lowerCount = 0;
    int numberCount = 0;
    int specialCount = 0;

    scanf("%*[(]");

    while ((c = getchar()) != ')')
    {
        if (EhLetraMaiuscula(c))
            upperCount++;
        else if (EhLetraMinuscula(c))
            lowerCount++;
        else if (EhNumero(c))
            numberCount++;
        else
            specialCount++;
    }

    scanf("%*[\n]");

    if (upperCount + lowerCount + numberCount + specialCount < 6)
        return 0;
    if (upperCount > 0 && lowerCount > 0 && numberCount > 0 && specialCount > 0)
        return 2;
    return 1;
}
