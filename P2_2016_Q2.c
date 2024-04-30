#include <stdio.h>

int EhPrimo(int num);
int MaiorDigitoPrimo(int num);

int main(int argc, char const *argv[])
{
    int n = 0;
    int sum = 0;
    while (scanf("%d", &n))
        sum += MaiorDigitoPrimo(n);

    printf("SOMA:%d", sum);

    return 0;
}

int EhPrimo(int num)
{
    int i = 0;
    int d = 0;

    for (i = 1; i <= num; i++)
        if (num % i == 0)
            d++;

    return d == 2;
}

int MaiorDigitoPrimo(int num)
{
    int copy = num;
    int max = 0;

    while (copy != 0)
    {
        int digit = copy % 10;
        if (EhPrimo(digit) && digit > max)
            max = digit;
        copy /= 10;
    }

    return max;
}
