#include <stdio.h>

typedef struct
{
    int idMensagem;
    int idPacote;
    int tamanhoMensagem;
    char mensagem[10];
    int idErro;
} tPacote;

tPacote LePacote();
void ImprimePacote(tPacote pacote);
int ContemErro(tPacote pacote);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        tPacote pacote = LePacote();
        if (ContemErro(pacote))
            printf("FALHA!\n");
        else
            ImprimePacote(pacote);
    }

    return 0;
}

tPacote LePacote()
{
    tPacote pacote;
    scanf("%3d", &pacote.idMensagem);
    scanf("%3d", &pacote.idPacote);
    scanf("%1d", &pacote.tamanhoMensagem);
    scanf("%9[^\n]s", pacote.mensagem);
    scanf("%4d\n", &pacote.idErro);
    return pacote;
}

void ImprimePacote(tPacote pacote)
{
    printf("PCT: ");
    printf("%d,", pacote.idMensagem);
    printf("%d,", pacote.idPacote);
    printf("%d,", pacote.tamanhoMensagem);
    char format[10];
    sprintf(format, "%%.%ds", pacote.tamanhoMensagem);
    printf(format, pacote.mensagem);
    printf(",%d\n", pacote.idErro);
}

int ContemErro(tPacote pacote)
{
    int somaMensagem = 0;
    int i = 0;
    for (i = 0; i < pacote.tamanhoMensagem; i++)
        somaMensagem += pacote.mensagem[i];
    return pacote.idMensagem +
               pacote.idPacote +
               pacote.tamanhoMensagem +
               somaMensagem !=
           pacote.idErro;
}
