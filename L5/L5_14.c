#include <stdio.h>
#include <stdlib.h>

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
int ComparaString(char *str1, char *str2);

int main()
{
    int qtdCand = 0, i = 0, j = 0;
    scanf("%d", &qtdCand);
    tCandidato candidatos[qtdCand];
    int impressos[qtdCand];
    for (i = 0; i < qtdCand; i++)
    {
        candidatos[i] = LeCandidato();
        impressos[i] = 0;
    }
    for (i = 0; i < qtdCand; i++)
    {
        int count = 0;
        for (j = 0; j < qtdCand; j++)
            if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome) && !impressos[j])
                count++;
        if (count > 1)
        {
            ImprimeCandidato(candidatos[i]);
            impressos[i] = 1;
            for (j = 0; j < qtdCand; j++)
                if (ComparaString(candidatos[i].sobrenome, candidatos[j].sobrenome) && !impressos[j])
                {
                    ImprimeCandidato(candidatos[j]);
                    impressos[j] = 1;
                }
        }
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

int ComparaString(char *str1, char *str2)
{
    int i = 0;
    int j = 0;
    int isEqual = 1;

    for (i = 0, j = 0; 1; i++, j++)
    {
        if (str1[i] == '\0' || str2[j] == '\0')
        {
            if (str1[i] != str2[j])
                isEqual = 0;
            break;
        }
        if (str1[i] == str2[j])
            continue;
        isEqual = 0;
        break;
    }

    return isEqual;
}