#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = 0;

    printf("RESP:");

    while (!(c == '?' || c == '!' || c == '.'))
    {
        scanf("%c", &c);

        if (c == ' ')
            c = '_';

        printf("%c", c);
    }

    return 0;
}
