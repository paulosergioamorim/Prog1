#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str[100];
    int i = 0;
    scanf("%s", str);

    printf("RESP:");
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] != '(')
            continue;

        for (i += 1; str[i] != ')' || str[i + 1] == ')'; i++)
            printf("%c", str[i]);

        if (str[i + 1] == '.')
            break;
    }

    return 0;
}
