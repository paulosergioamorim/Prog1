#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int k = 0;
    float pi = 0;
    scanf("%d", &n);

    for (k = 1; k <= n; k++)
        pi += 6.0 / (k * k);

    pi = sqrt(pi);
    printf("%.6f", pi);

    return 0;
}
