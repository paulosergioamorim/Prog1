#include <stdio.h>

int main()
{
    int x, y = 0;
    scanf("%d %d", &x, &y);
    float avg = (float) (x + y) / 2;
    if (avg >= 7)
        printf("%.1f - Aprovado", avg);
    else if (avg >= 5)
        printf("%.1f - De Recuperacao", avg);
    else
        printf("%.1f - Reprovado", avg);
    return 0;
}