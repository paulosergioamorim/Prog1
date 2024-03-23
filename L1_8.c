#include <stdio.h>

int main()
{
    char letra = 0;
    scanf("%c", &letra);

    if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U' || letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        printf("Vogal");
    else 
        printf("Nao vogal");
    return 0;
}