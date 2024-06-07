#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int a = 0;
    int b = 0;
    int count = 0;
    scanf("%d", &n);
    int numbers[n];
    for (i; i < n; i++)
        scanf("%d", &numbers[i]);
    scanf("%d %d", &a, &b);
    for (i = 0; i < n; i++)
        if (a <= numbers[i] && numbers[i] <= b)
            count++;
    printf("%d %d", count, n - count);
    return 0;
}
