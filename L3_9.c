#include <stdio.h>
#include <math.h>

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal);
float porcentagem(float total, float valor);
int verificaGotaChuvaAcida(float pH);
int verificapH(float pH);

int main(int argc, char const *argv[])
{
    int a = 0;
    int d = 0;
    int t = 0;
    int i = 0;
    int countAcidRain = 0;
    int countAcid = 0;
    int countBasic = 0;
    int countNeuter = 0;
    float maxAcid = 14;
    float maxBasic = 0;
    float maxNeuter = 0;
    
    scanf("%d %d %d", &a, &d, &t);

    for (i = 0; i < a * d * t; i++)
    {
        float p = 0;
        scanf("%f", &p);

        switch (verificapH(p))
        {
        case 0:
            countNeuter++;
            break;
        case 1:
            countAcid++;
            if (verificaGotaChuvaAcida(p))
                countAcidRain++;
            break;
        case 2:
            countBasic++;
            break;
        }

        if (p < maxAcid)
            maxAcid = p;
        if (p > maxBasic)
            maxBasic = p;
        if (fabs(7 - p) < fabs(7 - maxNeuter))
            maxNeuter = p;
    }

    if (a * d * t == 0)
    {
        printf("Nenhuma gota foi avaliada");
        return 0;
    }

    printf("%d %d %d %.2f %.2f %.2f\n", countAcid, countBasic, countNeuter, maxAcid, maxBasic, maxNeuter);

    imprimeResultadosAnalise(porcentagem(countAcid + countBasic + countNeuter, countAcidRain), porcentagem(countAcid + countBasic + countNeuter, countAcid + countBasic + countNeuter - countAcidRain));

    return 0;
}

void imprimeResultadosAnalise(float porcentagemGotasChuvaAcida, float porcentagemGotasChuvaNormal)
{
    if (porcentagemGotasChuvaAcida >= 75)
        printf("Chuva Acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    else if (porcentagemGotasChuvaNormal >= 75)
        printf("Chuva Normal %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
    else
        printf("Chuva com indicios de chuva acida %.2f%% %.2f%%", porcentagemGotasChuvaAcida, porcentagemGotasChuvaNormal);
}

float porcentagem(float total, float valor)
{
    return 100 * valor / total;
}

int verificaGotaChuvaAcida(float pH)
{
    return pH < 5.7;
}

int verificapH(float pH)
{
    if (pH < 7)
        return 1;
    if (pH > 7)
        return 2;
    return 0;
}
