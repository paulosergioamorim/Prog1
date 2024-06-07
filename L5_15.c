#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char sobrenome[21];
    char nome[21];
    int nota;
    int idade;
} tCandidato;

tCandidato LeCandidato();
void ImprimeCandidato(tCandidato candidato);
void OrdenaCrescente(tCandidato *vet, int qtd);
void ConcatenaString(char *str1, char *str2, char *strOut);

int main()
{
    int qtdCand, i = 0, j;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];
    for (i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
    }
    OrdenaCrescente(candidatos, qtdCand);
    for (i = 0; i < qtdCand; i++)
    {
        ImprimeCandidato(candidatos[i]);
    }
    return 0;
}

tCandidato LeCandidato()
{
    tCandidato candidato;
    scanf("%*[^{]");
    scanf("%*[{ ]");
    scanf("%d", &candidato.codigo);
    scanf("%*[, ]");
    scanf("%[^,],", candidato.sobrenome);
    scanf("%*[ ]");
    scanf("%[^,],", candidato.nome);
    scanf("%d", &candidato.nota);
    scanf("%*[, ]");
    scanf("%d", &candidato.idade);
    scanf("%*[^\n]\n");
    return candidato;
}

void ImprimeCandidato(tCandidato candidato)
{
    printf("CAND(%d): %s %s, Nota:%d, Idade:%d\n",
           candidato.codigo, candidato.nome,
           candidato.sobrenome, candidato.nota, candidato.idade);
}

void OrdenaCrescente(tCandidato *vet, int qtd)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < qtd; i++)
    {
        for (j = i + 1; j < qtd; j++) {
            char nome1[42];
            char nome2[42];
            ConcatenaString(vet[i].nome, vet[i].sobrenome, nome1);
            ConcatenaString(vet[j].nome, vet[j].sobrenome, nome2);
            if (strcmp(nome1, nome2) >= 0)
            {
                tCandidato c = vet[i];
                vet[i] = vet[j];
                vet[j] = c;
            }
        }
    }
}

void ConcatenaString(char *str1, char *str2, char *strOut)
{
    int i = 0;
    int j = 0;

    for (i = 0; str1[i] != '\0'; i++)
        strOut[i] = str1[i];

    for (j = 0; 1; i++, j++)
    {
        strOut[i] = str2[j];
        if (str2[j] == '\0')
            break;
    }
}