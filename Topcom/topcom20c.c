#include <stdio.h>

int main(int argc, char const *argv[])
{
    long int n = 0;
    long int m = 0;
    long int d = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    scanf("%ld %ld %ld\n", &n, &m, &d);
    long int estudantes[n];
    long int apartamentos[m];
    int ocupados[m];

    for (i = 0; i < n; i++)
        scanf("%ld", &estudantes[i]);

    for (i = 0; i < m; i++)
    {
        scanf("%ld", &apartamentos[i]);
        ocupados[i] = 0;
    }

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (estudantes[i] - d <= apartamentos[j] && apartamentos[j] <= estudantes[i] + d && ocupados[j] == 0)
            {
                ocupados[j] = 1;
                count++;
                break;
            }

    printf("%d", count);
    return 0;
}
