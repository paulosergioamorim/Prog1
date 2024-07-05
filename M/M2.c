#include <stdio.h>

int main()
{
    float x = 0;
    scanf("%f", &x);
    int y = (int) x;
    float z = x - y;
    printf("INTEIRO:%d,REAL:%.2f", y, z);
    return 0;
}