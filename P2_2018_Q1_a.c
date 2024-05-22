#include <stdio.h>

int is_even(int x);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int x = 0;
    int sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (is_even(i))
        {
            if (is_even(x))
                sum += x;
        }
        else
        {
            if (!is_even(x))
                sum += x;
        }
    }

    printf("SOMA:%d", sum);

    return 0;
}

int is_even(int x)
{
    return x % 2 == 0;
}
