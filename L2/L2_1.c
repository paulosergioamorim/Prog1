#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, m = 0;
    scanf("%d %d", &n, &m);
    n++;
    printf("RESP:");
    while (n < m) {
        if (n % 2 == 0)
            printf("%d ", n);
        n++;
    }
    return 0;
}
