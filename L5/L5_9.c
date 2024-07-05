#include <stdio.h>

void InverteVetor(int *vet, int qtd);
void ImprimeDadosDoVetor(int vet[], int qtd);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++)
        scanf("%d", &vet[i]);
    InverteVetor(vet, n);
    ImprimeDadosDoVetor(vet, n);
    return 0;
}

void ImprimeDadosDoVetor(int vet[], int qtd)
{
    int i = 0;
    printf("{");
    for (i = 0; i < qtd; i++)
    {
        printf("%d", vet[i]);
        if (i < qtd - 1)
            printf(", ");
    }
    printf("}");
}

void InverteVetor(int *vet, int qtd)
{
    int i = 0;
    int newVet[qtd];
    for (i = 0; i < qtd; i++)
        newVet[i] = vet[qtd - i - 1];
    for (i = 0; i < qtd; i++)
        vet[i] = newVet[i];
}
