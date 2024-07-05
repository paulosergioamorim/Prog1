#include <stdio.h>

int main()
{
    float x, y = 0;
    scanf("%f %f", &x, &y);
    float z = 2 * (x + y);
    printf("%.2f", z);
    return 0;
}