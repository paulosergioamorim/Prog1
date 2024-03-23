#include <stdio.h>

int main() {
    float a, b, c, d = 0;
    scanf("%f %f %f %f", &a, &b, &c, &d);
    float x = 2 * (c - a + d - b);
    printf("%.2f", x);
    return 0;
}