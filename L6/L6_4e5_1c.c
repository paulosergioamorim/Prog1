#include <stdio.h>

typedef struct
{
    int idMensagem;
    int idPacote;
    int tamanhoMensagem;
    char mensagem[10];
    int idErro;
} tPacote;

typedef struct
{
    int numPacotes;
    tPacote pacotes[100];
} tMensagens;

tPacote LePacote();
void ImprimeMensagemPacote(tPacote pacote);
int ContemErro(tPacote pacote);
int OrdenaPacotes(int n, tPacote pacotes[n]);
int MesmaMensagem(tPacote pacote1, tPacote pacote2);
void ImprimeMensagem(tMensagens mensagem);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    scanf("%d\n", &n);

    tMensagens mensagens[n];
    tPacote pacotes[n];

    for (i = 0; i < n; i++)
        pacotes[i] = LePacote();

    OrdenaPacotes(n, pacotes);

    for (i = 0, k = 0; k < n; i++)
    {
        if (i != 0)
            printf("\n");
        for (j = 0; j == 0 || MesmaMensagem(pacotes[k - 1], pacotes[k]); j++, k++)
            mensagens[i].pacotes[j] = pacotes[k];
        mensagens[i].numPacotes = j;
        ImprimeMensagem(mensagens[i]);
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

void ImprimeMensagemPacote(tPacote pacote)
{
    char format[10];
    sprintf(format, "%%.%ds", pacote.tamanhoMensagem);
    printf(format, pacote.mensagem);
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

int OrdenaPacotes(int n, tPacote pacotes[n])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (pacotes[i].idMensagem > pacotes[j].idMensagem)
            {
                tPacote c = pacotes[i];
                pacotes[i] = pacotes[j];
                pacotes[j] = c;
            }

    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (MesmaMensagem(pacotes[i], pacotes[j]) &&
                pacotes[i].idPacote > pacotes[j].idPacote)
            {
                tPacote c = pacotes[i];
                pacotes[i] = pacotes[j];
                pacotes[j] = c;
            }

    return 0;
}

int MesmaMensagem(tPacote pacote1, tPacote pacote2)
{
    return pacote1.idMensagem == pacote2.idMensagem;
}

void ImprimeMensagem(tMensagens mensagem)
{
    int i = 0;
    for (i = 0; i < mensagem.numPacotes; i++)
    {
        if (ContemErro(mensagem.pacotes[i]))
            printf("##FALHA##");
        else
            ImprimeMensagemPacote(mensagem.pacotes[i]);
    }
}
