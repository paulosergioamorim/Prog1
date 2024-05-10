#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c = 0;
    int count = 0;
    int i = 0;

    printf("RESP:");

    while (c != '.')
    {
        scanf("%c", &c);

        if (c != '(')
            continue;

        for (count = 0; c == '('; count++)
        {
            scanf("%c", &c);
            if (count > 0)
                printf("(");
        }

        while (c != ')')
        {
            printf("%c", c);
            scanf("%c", &c);
        }

        for (count; count > 1; count--)
        {
            scanf("%c", &c);
            printf(")");
        }
    }

    return 0;
}
