#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int div = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        if (n % i == 0)
            div++;

    printf(div == 2 ? "Primo" : "Nao primo");

    return 0;
}
