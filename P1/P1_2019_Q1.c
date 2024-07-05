#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 0;
    int z = 0;
    scanf("%d %d %d", &x, &y, &z);
    if (x < y && y < z)
        printf("CRESCENTE");
    else if (x > y && y > z)
        printf("DECRESCENTE");
    else
        printf("TUDO DOIDO");
    return 0;
}
