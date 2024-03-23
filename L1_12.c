#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    if (a < b && a < c)
    {
        if (b < c)
            printf("N1 = %d, N2 = %d, N3 = %d", a, b, c);
        else
            printf("N1 = %d, N3 = %d, N2 = %d", a, c, b);
    }
    if (b < a && b < c)
    {
        if (a < c)
            printf("N2 = %d, N1 = %d, N3 = %d", b, a, c);
        else
            printf("N2 = %d, N3 = %d, N1 = %d", b, c, a);
    }
    if (c < a && c < b)
    {
        if (a < b)
            printf("N3 = %d, N1 = %d, N2 = %d", c, a, b);
        else
            printf("N3 = %d, N2 = %d, N1 = %d", c, b, a);
    }

    return 0;
}
