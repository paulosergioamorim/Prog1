#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int x = 0;
    scanf("%d %d", &x, &n);
    int j = n;
    int numbers[n];
    for (i; i < n; i++)
        scanf("%d", &numbers[i]);
    for (i = 0; i < n; i++)
        if (numbers[i] == x)
        {
            j = i;
            break;
        }
    printf("RESP:%d", j);
    return 0;
}
