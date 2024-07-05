#include <stdio.h>

void sort(int vet[], int qtd);

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    scanf("%d", &n);
    int vetA[n];
    for (i = 0; i < n; i++)
        scanf("%d", &vetA[i]);
    scanf("%d", &m);
    int vetB[m];
    for (i = 0; i < m; i++)
        scanf("%d", &vetB[i]);
    sort(vetA, n);
    sort(vetB, m);
    int count = 0;
    for (i = 0, j = 0, count = 0; count < n + m; count++)
    {
        if (i >= n)
        {
            printf("B");
            j++;
        }
        else if (j >= m)
        {
            printf("A");
            i++;
        }
        else if (vetA[i] <= vetB[j])
        {
            printf("A");
            i++;
        }
        else
        {
            printf("B");
            j++;
        }
    }
    return 0;
}

void sort(int vet[], int qtd)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < qtd; i++)
        for (j = i + 1; j < qtd; j++)
            if (vet[i] > vet[j])
            {
                int c = vet[i];
                vet[i] = vet[j];
                vet[j] = c;
            }
}
