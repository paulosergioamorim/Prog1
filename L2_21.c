#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;
    int x5 = 0;
    int x6 = 0;
    int x7 = 0;
    int x8 = 0;
    int x9 = 0;
    char c = 0;

    scanf("%d %d %d %d %d %d %d %d %d %d", &n, &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9);

    while (1)
    {
        scanf("%c", &c);

        if (c == '\n')
            return 0;

        if (c == '"')
            continue;

        if (c != '%')
        {
            printf("%c", c);
            continue;
        }

        scanf("%c", &c);

        if (c - '0' > n) {
            printf("ERRO");
            continue;
        }

        switch (c - '0')
        {
        case 1:
            printf("%d", x1);
            break;
        case 2:
            printf("%d", x2);
            break;
        case 3:
            printf("%d", x3);
            break;
        case 4:
            printf("%d", x4);
            break;
        case 5:
            printf("%d", x5);
            break;
        case 6:
            printf("%d", x6);
            break;
        case 7:
            printf("%d", x7);
            break;
        case 8:
            printf("%d", x8);
            break;
        case 9:
            printf("%d", x9);
            break;
        default:
            printf("ERRO");
            break;
        }
    }
}
