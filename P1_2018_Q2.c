#include <stdio.h>

int conta_notas(int troco)
{
    return troco / 5 + troco % 5;
}

int main(int argc, char const *argv[])
{
    int troco1 = 0;
    int troco2 = 0;
    scanf("%d %d", &troco1, &troco2);
    int qtdNotas1 = conta_notas(troco1);
    int qtdNotas2 = conta_notas(troco2);
    if (qtdNotas1 == qtdNotas2)
        printf("Iguais!");
    else if (qtdNotas1 > qtdNotas2)
        printf("QTD troco 1 eh maior!");
    else
        printf("QTD troco 2 eh maior!");
    return 0;
}
