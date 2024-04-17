#include <stdio.h>
#include <math.h>

float f_x(float a, float b, float c, float d, int x)
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

    p, v = f + 1;

    for (i = e; i <= f; i++)
    {
        if (i == e)
        {
            if (f_x(a, b, c, d, i) > f_x(a, b, c, d, i + 1))
                p = i;
            else if (f_x(a, b, c, d, i) < f_x(a, b, c, d, i + 1))
                v = i;
            continue;
        }

        if (f_x(a, b, c, d, i - 1) < f_x(a, b, c, d, i) && f_x(a, b, c, d, i) > f_x(a, b, c, d, i + 1))
            p = i;
        else if (f_x(a, b, c, d, i - 1) > f_x(a, b, c, d, i) && f_x(a, b, c, d, i) < f_x(a, b, c, d, i + 1))
            v = i;

        if (i == f)
        {
            if (f_x(a, b, c, d, i - 1) < f_x(a, b, c, d, i))
                p = i;
            else if (f_x(a, b, c, d, i - 1) > f_x(a, b, c, d, i))
                v = i;
            continue;
        }
    }

    if (p >= e && p <= f)
        printf("Pico em x=%d\n", p);
    else
        printf("Nao ha pico");
    if (v >= e && v <= f)
        printf("Vale em x=%d\n", v);
    else
        printf("Nao ha vale");

    return 0;
}
