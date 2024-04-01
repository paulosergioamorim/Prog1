#include <stdio.h>
#include <string.h>

void remove_spaces(char *s)
{
    char *d = s;
    do
        while (*d == ' ')
            ++d;
    while (*s++ = *d++);
}

int main(int argc, char const *argv[])
{
    char s[100] = "";
    scanf("%[^\n]", s);
    int i = 0;
    int j = 0;
    remove_spaces(s);
    printf("RESP:%s", s);
    return 0;
}
