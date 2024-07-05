#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c, d, e, f = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    if (c > a)
    {
        if (d > b)
        {
            if (a < e && e < c && b < f && f < d)
                printf("Dentro");
            else
                printf("Fora");
        }
        else
        {
            if (a < e && e < c && d < f && f < b)
                printf("Dentro");
            else
                printf("Fora");
        }
    }
    else
    {
        if (d > b)
        {
            if (c < e && e < a && b < f && f < d)
                printf("Dentro");
            else
                printf("Fora");
        }
        else {
            if (c < e && e < a && d < f && f < b)
                printf("Dentro");
            else
                printf("Fora");
        }
    }
    return 0;
}
