#include <stdio.h>

int main()
{
    char letra = 0;
    scanf("%c", &letra);

    if (letra >= 65 && letra <= 90)
        printf("A letra deve ser minuscula!");
    else if (letra >= 97 && letra <= 122)
    {
        char letraMaiuscula = letra - 32;
        printf("%c(%d)", letraMaiuscula, letraMaiuscula);
    }
    else
        printf("Nao e letra!");

    return 0;
}