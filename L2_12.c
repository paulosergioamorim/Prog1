#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[100] = "";
    scanf("%[^\n]", s);
    size_t i = 0;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' ')
            s[i] = '_';
        if (s[i] == '?' || s[i] == '!' || s[i] == '.')
            break;
    }

    printf("RESP:%s", s);
    return 0;
}
