#include <stdio.h>

int main(int argc, char const *argv[])
{
    int i = 0;
    int j = 0;
    int min = __INT_MAX__;
    int first = -1;
    int last = -1;

    for (j = 0; scanf("%d ", &i); j++)
        if (i < min)
            min = i;

    scanf("%*[^\n]");

    for (j = 0; scanf("%d ", &i); j++)
        if (i == min)
        {
            if (first == -1)
                first = j;
            last = j;
        }

    if (first == -1)
        printf("%d %d %d", min, j, j);
    else
        printf("%d %d %d", min, first, last);

    return 0;
}
