#include <stdio.h>
#define ESCOVADO 1
#define ARRUMADO 1
#define PREPARADO 1
#define PENDENTE 0

void EscovarDentes();
void ArrumarCama();
void PrepararCafe();

int dentes = PENDENTE;
int cama = PENDENTE;
int cafe = PENDENTE;

int main(int argc, char const *argv[])
{
    while (1)
    {
        int tarefa = 0;
        scanf("%d", &tarefa);

        if (tarefa == 1)
        {
            EscovarDentes();
            continue;
        }

        if (tarefa == 2)
        {
            ArrumarCama();
            continue;
        }

        if (tarefa == 3)
        {
            PrepararCafe();
            continue;
        }

        if (dentes == PENDENTE || cama == PENDENTE || cafe == PENDENTE)
        {
            printf("### Ainda ha tarefas pendentes! ###\n");
            continue;
        }

        printf("Saindo de casa!\n");

        return 0;
    }
}

void EscovarDentes()
{
    if (dentes == ESCOVADO)
    {
        printf("Isso ja foi feito!\n");
        return;
    }

    printf("Escovando os dentes!\n");
    dentes = ESCOVADO;
}

void ArrumarCama()
{
    if (cama == ARRUMADO)
    {
        printf("Isso ja foi feito!\n");
        return;
    }

    printf("Arrumando a cama!\n");
    cama = ARRUMADO;
}

void PrepararCafe()
{
    if (cafe == PREPARADO)
    {
        printf("Isso ja foi feito!\n");
        return;
    }

    printf("Preparando o cafe!\n");
    cafe = PREPARADO;
}
