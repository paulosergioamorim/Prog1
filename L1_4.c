#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main()
{
    float r = 0;
    scanf("%f", &r);
    float a = r * r * PI;
    float r2 = sqrt(a / (2 * PI));
    printf("%.2f %.2f", a, r2);
    return 0;
}