#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    double sum = 0;

    scanf("%d", &n);

    if (n == 1)
        for (i = 1; i <= 50; i++)
            sum += (double)(2 * i - 1) / i;
    else if (n == 2)
        for (i = 50; i > 0; i--)
            sum += pow(2, 51 - i) / i;
    else if (n == 3)
        for (i = 1; i <= 10; i++)
            sum += (double)i / pow(i, 2);

    printf("%.6f", sum);

    return 0;
}
