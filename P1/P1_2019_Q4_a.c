#include <stdio.h>

int get_10th_valid_digit(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9);
int get_11th_valid_digit(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10);

int main(int argc, char const *argv[])
{
    int x1 = 0;
    int x2 = 0;
    int x3 = 0;
    int x4 = 0;
    int x5 = 0;
    int x6 = 0;
    int x7 = 0;
    int x8 = 0;
    int x9 = 0;
    int x10 = 0;
    int x11 = 0;
    scanf("%1d%1d%1d.%1d%1d%1d.%1d%1d%1d-%1d%1d", &x1, &x2, &x3, &x4, &x5, &x6, &x7, &x8, &x9, &x10, &x11);
    int valid10thDigit = get_10th_valid_digit(x1, x2, x3, x4, x5, x6, x7, x8, x9);
    int valid11thDigit = get_11th_valid_digit(x1, x2, x3, x4, x5, x6, x7, x8, x9, valid10thDigit);
    if (x1 == x2 && x2 == x3 && x3 == x4 && x4 == x5 && x5 == x6 && x6 == x7 && x7 == x8 && x8 == x9 && x9 == x10 && x10 == x11)
        printf("CPF invalido: digitos iguais!");
    else if (valid10thDigit != x10 && valid11thDigit != x11)
        printf("CPF invalido: dois digitos!");
    else if (valid10thDigit != x10)
        printf("CPF invalido: primeiro digito!");
    else if (valid11thDigit != x11)
        printf("CPF invalido: segundo digito!");
    else
        printf("CPF valido!");
    return 0;
}

int get_10th_valid_digit(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9)
{
    int sum = x1 * 10 + x2 * 9 + x3 * 8 + x4 * 7 + x5 * 6 + x6 * 5 + x7 * 4 + x8 * 3 + x9 * 2;
    int rest = sum % 11;
    if (rest < 2)
        return 0;
    return 11 - rest;
}

int get_11th_valid_digit(int x1, int x2, int x3, int x4, int x5, int x6, int x7, int x8, int x9, int x10)
{
    int sum = x1 * 11 + x2 * 10 + x3 * 9 + x4 * 8 + x5 * 7 + x6 * 6 + x7 * 5 + x8 * 4 + x9 * 3 + x10 * 2;
    int rest = sum % 11;
    if (rest < 2)
        return 0;
    return 11 - rest;
}
