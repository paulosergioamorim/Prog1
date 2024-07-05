#include <stdio.h>
#include <stdlib.h>

void ConcatenaString(char *str1, char *str2, char *strOut);

int main()
{
    char nome[1000];
    char sobrenome[1000];
    char nomeCompleto[2000];
    while (scanf("%s", sobrenome) == 1 && scanf("%s", nome) == 1)
    {
        ConcatenaString(nome, sobrenome, nomeCompleto);
        printf("%s\n", nomeCompleto);
    }
    return 0;
}

void ConcatenaString(char *str1, char *str2, char *strOut)
{
    int i = 0;
    int j = 0;

    for (i = 0; str1[i] != '\0'; i++)
        strOut[i] = str1[i];

    for (j = 0; 1; i++, j++)
    {
        strOut[i] = str2[j];
        if (str2[j] == '\0')
            break;
    }
}
