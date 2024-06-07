#include <stdio.h>
#include <stdlib.h>

int ComparaString(char *str1, char *str2);

int main()
{
    char str1[1000];
    char str2[1000];
    while (scanf("%s", str1) == 1 && scanf("%s", str2) == 1)
    {
        if (ComparaString(str1, str2))
            printf("IGUAL\n");
        else
            printf("DIFERENTE\n");
    }
    return 0;
}

int ComparaString(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int isEqual = 1;

    for (i = 0, j = 0; 1; i++, j++)
    {
        if (str1[i] == '\0' || str2[j] == '\0')
        {
            if (str1[i] != str2[j])
                isEqual = 0;
            break;
        }
        if (str1[i] == str2[j])
            continue;
        isEqual = 0;
        break;
    }

    return isEqual;
}
