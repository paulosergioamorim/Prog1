#include <stdio.h>

int EhFinalDaLista(int buraco);
int EncontraMaiorBuraco();
int ContaEsferasGrandes(int maiorBuraco);

int main(int argc, char const *argv[])
{
    int maiorBuraco = EncontraMaiorBuraco();
    int qtd = ContaEsferasGrandes(maiorBuraco);
    printf("QTD:%d\n", qtd);
    return 0;
}

int EhFinalDaLista(int buraco)
{
    return buraco == -1;
}

int EncontraMaiorBuraco()
{
    int maior = 0;
    int buraco = 0;
    while (1)
    {
        scanf("%d", &buraco);
        if (EhFinalDaLista(buraco))
            break;
        if (buraco > maior)
            maior = buraco;
    }
    return maior;
}

int ContaEsferasGrandes(int maiorBuraco)
{
    int qtd = 0;
    int esfera = 0;
    while (1)
    {
        scanf("%d", &esfera);
        if (EhFinalDaLista(esfera))
            break;
        if (esfera >= maiorBuraco)
            qtd++;
    }
    return qtd;
}
