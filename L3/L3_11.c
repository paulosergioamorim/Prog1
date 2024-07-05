#include <stdio.h>

int EhPar(int x);
void PrintaPares(int N);
void PrintaImpares(int N);

int main(int argc, char const *argv[])
{
    int t = 0;
    int n = 0;
    scanf("%d %d", &t, &n);

    if (t == 0)
        PrintaPares(n);
    else
        PrintaImpares(n);

    return 0;
}

int EhPar(int x)
{
    return x % 2 == 0;
}

void PrintaPares(int N)
{
    int i = 0;
    int j = 0;
    for (i = 1; j < N; i++)
    {
        if (!EhPar(i))
            continue;
        printf("%d ", i);
        j++;
    }
}

void PrintaImpares(int N)
{
    int i = 0;
    int j = 0;
    for (i = 1; j < N; i++)
    {
        if (EhPar(i))
            continue;
        printf("%d ", i);
        j++;
    }
}
