#include <stdio.h>

int main()
{
    int p, i = 0;
    scanf("%d %d", &p, &i);
    if (p > i)
        printf("RESP:%d", 0);
    else
        printf("RESP:%d", p % i);
    return 0;
}
