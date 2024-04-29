#include <stdio.h>
#define ESCOVADO 1
#define ARRUMADO 1
#define PREPARADO 1
#define PENDENDTE 0

void EscovarDentes();
void ArrumarCama();
void PrepararCafe();

int main(int argc, char const *argv[])
{
    int dentes = PENDENDTE;
    int cama = PENDENDTE;
    int cafe = PENDENDTE;

    while (1)
    {
        int tarefa = 0;
        scanf("%d", &tarefa);
        
        if (tarefa == 1) {
            EscovarDentes();
            continue;
        }

        if (tarefa == 2) {
            ArrumarCama();
            continue;
        }

        if (tarefa == 3) {
            PrepararCafe();
            continue;
        }

        if (!dentes || !cama || !cafe)
        {
            printf("### Ainda ha tarefas pendentes! ###");
            continue;
        }

        break;
    }
    return 0;
}

void EscovarDentes()
{
}

void ArrumarCama()
{
}

void PrepararCafe()
{
}
