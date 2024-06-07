#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int maxDiff = 0;
    scanf("%d", &n);

    if (n < 2)
    {
        printf("IMPOSSIVEL");
        return 0;
    }

    int pairsCount = 0;
    int heigths[n];
    int pairs[n];

    for (i; i < n; i++)
        scanf("%d", &heigths[i]);

    for (i = 1; i < n; i++)
    {
        int diff = abs(heigths[i] - heigths[i - 1]);
        if (diff > maxDiff)
        {
            maxDiff = diff;
            pairsCount = 2;
            pairs[0] = i - 1;
            pairs[1] = i;
        }
        else if (diff == maxDiff)
        {
            pairs[pairsCount] = i - 1;
            pairs[pairsCount + 1] = i;
            pairsCount += 2;
        }
    }

    for (i = 0; i < pairsCount; i += 2)
        printf(" (%d %d)", pairs[i], pairs[i + 1]);

    return 0;
}
