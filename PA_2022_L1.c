#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int n = 0;
    char c = '\0';

    scanf("(%c,%d,%d)", &c, &a, &b);

    int uA = a % 10;
    int dA = (a - uA) / 10 % 10;
    int cA = (a - uA - dA) / 100 % 10;
    int mA = (a - uA - dA - cA) / 1000 % 10;
    int uB = b % 10;
    int dB = (b - uB) / 10 % 10;
    int cB = (b - uB - dB) / 100 % 10;
    int mB = (b - uB - dB - cB) / 1000 % 10;

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        n = pow(10, 0) * uA + pow(10, 1) * uB + pow(10, 2) * dA + pow(10, 3) * dB + pow(10, 4) * cA + pow(10, 5) * cB + pow(10, 6) * mA + pow(10, 7) * mB;
    else
        n = pow(10, 0) * uB + pow(10, 1) * uA + pow(10, 2) * dB + pow(10, 3) * dA + pow(10, 4) * cB + pow(10, 5) * cA + pow(10, 6) * mB + pow(10, 7) * mA;

    printf("(%d)\n", n);

    return 0;
}
