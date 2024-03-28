#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n, m = 0;
    scanf("%d %d", &n, &m);
    n++;
    while (n < m) {
        if (n % 3 == 0 || n % 4 == 0 || n % 7 == 0)
            printf("%d ", n);
        n++;
    }
    return 0;
}
