#include <stdio.h>
#include <math.h>

float fX(float a, float b, float c, float d, int x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main(int argc, char const *argv[])
{
    float a = 0;
    float b = 0;
    float c = 0;
    float d = 0;
    int e = 0;
    int f = 0;
    int i = 0;
    int p = 0;
    int v = 0;

    scanf("%f %f %f %f %d %d", &a, &b, &c, &d, &e, &f);

    p = f + 1;
    v = f + 1;

    for (i = e + 1; i <= f - 1; i++)
    {
        if (fX(a, b, c, d, i - 1) < fX(a, b, c, d, i) && fX(a, b, c, d, i) > fX(a, b, c, d, i + 1))
            p = i;
        if (fX(a, b, c, d, i - 1) > fX(a, b, c, d, i) && fX(a, b, c, d, i) < fX(a, b, c, d, i + 1))
            v = i;
    }

    if (p < v)
    {
        if (p >= e && p <= f)
            printf("Pico em x=%d\n", p);
        if (v >= e && v <= f)
            printf("Vale em x=%d\n", v);
        if (p < e || p > f)
            printf("Nao ha pico\n");
        if (v < e || v > f)
            printf("Nao ha vale");
    }
    else
    {
        if (v >= e && v <= f)
            printf("Vale em x=%d\n", v);
        if (p >= e && p <= f)
            printf("Pico em x=%d\n", p);
        if (p < e || p > f)
            printf("Nao ha pico\n");
        if (v < e || v > f)
            printf("Nao ha vale");
    }

    return 0;
}
