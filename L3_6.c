#include <stdio.h>

int EhPalindromo(int num)
{
    int copy = num;
    int reverse = 0;

    while (copy != 0)
    {
        reverse *= 10;
        reverse += copy % 10;
        copy /= 10;
    }

    return reverse == num;
}

int main(int argc, char const *argv[])
{
    int n = 0;
    char c = 0;

    while (scanf("%d%c", &n, &c) == 2)
        printf(EhPalindromo(n) ? "S\n" : "N\n");

    return 0;
}
