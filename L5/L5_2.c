#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int isAscending = 1;
    int isDescending = 1;
    scanf("%d", &n);

    int numbers[n];

    for (i; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = 1; i < n; i++)
    {
        if (isAscending && numbers[i] < numbers[i - 1])
            isAscending = 0;
        if (isDescending && numbers[i] > numbers[i - 1])
            isDescending = 0;
    }

    if (isAscending && isDescending)
        printf("CRESCENTE&DECRESCENTE");
    else if (isAscending)
        printf("CRESCENTE");
    else if (isDescending)
        printf("DECRESCENTE");
    else
        printf("DESORDENADO");

        return 0;
}
