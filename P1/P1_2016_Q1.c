#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;

    scanf("%d", &i);

    if (i == 1)
        printf("Domingo");
    else if (i == 2)
        printf("Segunda");
    else if (i == 3)
        printf("Terca");
    else if (i == 4)
        printf("Quarta");
    else if (i == 5)
        printf("Quinta");
    else if (i == 6)
        printf("Sexta");
    else if (i == 7)
        printf("Sabado");
    else
        printf("Invalido");

    return 0;
}
