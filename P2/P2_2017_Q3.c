#include <stdio.h>

int QtdDebitoPlaca(int presc);
int MaiorDebidoCidade();

int main(int argc, char const *argv[])
{
    int n = 0;
    int sum = 0;
    scanf("%d", &n);

    for (n; n > 0; n--)
        sum += MaiorDebidoCidade();

    printf("SOMA:%d\n", sum);

    return 0;
}

int QtdDebitoPlaca(int presc)
{
    int accDebit = 0;
    int valDebit = 0;
    int yearDebit = 0;

    while (scanf("(%d:%d)", &valDebit, &yearDebit))
        if (yearDebit <= presc)
            accDebit += valDebit;

    return accDebit;
}

int MaiorDebidoCidade()
{
    int p = 0;
    char maxC1 = 0;
    char maxC2 = 0;
    char maxC3 = 0;
    int maxDebit = 0;
    scanf("%d", &p);

    while (1)
    {
        char c1 = 0;
        char c2 = 0;
        char c3 = 0;

        scanf("%*[\n]%c%c%c", &c1, &c2, &c3);

        if (c1 == 'F' && c2 == 'I' && c3 == 'M')
            break;

        int accDebit = QtdDebitoPlaca(p);

        if (accDebit > maxDebit)
        {
            maxDebit = accDebit;
            maxC1 = c1;
            maxC2 = c2;
            maxC3 = c3;
        }
    }

    if (maxC1 != 0 && maxC2 != 0 && maxC3 != 0)
        printf("PLACA:%c%c%c DEBITO:%d\n", maxC1, maxC2, maxC3, maxDebit);
    else
        printf("SEM DEBITO!\n");

    return maxDebit;
}
