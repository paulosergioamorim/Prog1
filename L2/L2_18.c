#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int a = 0;
    int b = 0;
    int u = INT_MIN;
    int v = 0;

    scanf("%d %d\n", &i, &j);

    for (k = 1; k <= i; k++)
        for (l = 1; l <= j; l++)
        {
            scanf("%d", &v);
            if (v <= u)
                continue;
            u = v;
            a = k;
            b = l;
        }

    printf("%d (%d, %d)", u, a, b);

    return 0;
}
