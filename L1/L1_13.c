#include <stdio.h>

int main()
{
    int p, i = 0;
    scanf("%d %d", &p, &i);
    int r = i % p;
    printf("RESP:%d", (r == 0) ? p : r);
    return 0;
}
