#include <stdio.h>

int main()
{
    int x, y = 0;
    scanf("%d %d", &x, &y);

    if (x == y)
        printf("N1 = N2");
    else if (x > y)
        printf("N1 = %d", x);
    else
        printf("N2 = %d", y);

    return 0;
}