#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;

    scanf("%d %d %d", &n1, &n2, &n3);

    int c1 = n1 / 100 % 10;
    int c2 = n2 / 100 % 10;
    int c3 = n3 / 100 % 10;

    if (n1 < 100 && n2 < 100 && n3 < 100)
        return printf("Nenhum");

    if (n1 >= 100)
    {
        if (c1 <= c2 && c2 <= c3)
            return printf("N1");
        else if (c1 <= c3 && c3 < c2)
            return printf("N1");
    }
    else
    {
        if (c2 <= c3)
            return printf("N2");
        else
            return printf("N3");
    }
    if (n2 >= 100)
    {
        if (c2 < c1 && c1 <= c3)
            return printf("N2");
        else if (c2 <= c3 && c3 < c1)
            return printf("N2");
    }
    else
    {
        if (c1 <= c3)
            return printf("N1");
        else
            return printf("N3");
    }
    if (n3 >= 100)
    {
        if (c3 < c1 && c1 <= c2)
            return printf("N3");
        else if (c3 < c2 && c2 < c1)
            return printf("N3");
    }
    else
    {
        if (c1 <= c2)
            return printf("N1");
        else
            return printf("N2");
    }

    return 0;
}
