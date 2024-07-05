#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int numbers[n];
    for (i; i < n; i++)
        scanf("%d", &numbers[i]);
    if (n == 1)
    {
        printf("NAO");
        return 0;
    }
    int diff = numbers[1] - numbers[0];
    for (i = 0; i < n - 1; i++)
        if (numbers[i + 1] - numbers[i] != diff)
        {
            printf("NAO");
            return 0;
        }
    printf("RESP:%d", diff);
    return 0;
}
