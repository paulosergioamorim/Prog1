#include <stdio.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} tData;

tData LeData();
int EhBisexto(tData data);
void ImprimeData(tData data);

int main(int argc, char const *argv[])
{
    int i = 0;
    scanf("%d", &i);

    for (i; i > 0; i--)
    {
        tData data = LeData();
        ImprimeData(data);
        printf(":");
        printf(EhBisexto(data) ? "Bisexto\n" : "Normal\n");
    }
}

tData LeData()
{
    int dia = 0;
    int mes = 0;
    int ano = 0;
    scanf("%d %d %d", &dia, &mes, &ano);

    if (dia < 1)
        dia = 1;
    if (mes < 1)
        mes = 1;
    if (mes > 12)
        mes = 12;
    else if (mes == 2)
    {
        if (dia > 28)
            dia = 28;
    }
    else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        if (dia > 31)
            dia = 31;
    }
    else if (dia > 30)
        dia = 30;

    tData data = {dia, mes, ano};

    return data;
}

int EhBisexto(tData data)
{
    return data.ano % 4 == 0 || (data.ano % 100 == 0 && data.ano % 400 == 0);
}

void ImprimeData(tData data)
{
    printf("'");
    if (data.dia < 10)
        printf("0");
    printf("%d/", data.dia);
    if (data.mes < 10)
        printf("0");
    printf("%d/", data.mes);
    printf("%d'", data.ano);
}
