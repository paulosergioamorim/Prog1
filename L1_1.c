#include <stdio.h>
#include <math.h>

int main()
{
    int x, y = 0;
    scanf("%d %d", &x, &y);
    float sqrtX = sqrt(x);
    float sqrtY = sqrt(y);
    printf("%.2f", sqrtX + sqrtY);
    return 0;
}