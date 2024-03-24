#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, m = 0;
    scanf("%d %d", &n, &m);

    int u = n % 10;
    int d = (n - u) / 10 % 10;
    int c = (n - d - u) / 10 % 10;

    if (m == 1)
        printf(u % 2 == 0 ? "PAR" : "IMPAR");
    else if (m == 2)
        printf(d % 2 == 0 ? "PAR" : "IMPAR");
    else if (m == 3)
        printf(c % 2 == 0 ? "PAR" : "IMPAR");

    return 0;
}
