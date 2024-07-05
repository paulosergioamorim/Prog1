#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;
    int n = 0;
    int max = -1;
    int sum = 0;
    float avg = 0;

    for (i = 1; 1; i++)
    {
        scanf("%d", &n);
        if (n == 0)
            break;
        if (n > max)
            max = n;
        sum += n;
        avg = (float)sum / i;
        printf("%d %.6f\n", max, avg);
    };

    return 0;
}
