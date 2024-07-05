#include <stdio.h>

#define MAX_CARTELA 7
#define MAX_PARTIDA 100
#define MAX_NUMEROS 100

typedef struct
{
    int id;
    int len;
    int numerosIniciais[MAX_CARTELA][MAX_CARTELA];
    int numerosMarcados[MAX_CARTELA][MAX_CARTELA];
} tCartela;

typedef struct
{
    int len;
    tCartela cartelas[MAX_PARTIDA];
} tPartida;

tPartida LeCartelasPartida();
tPartida ResetaPartida(tPartida partida);
tCartela LeCartela();
tCartela MarcaCartela(tCartela cartela, int numero);
int VenceuCartela(tCartela cartela);
void ImprimeCartela(tCartela cartela);
void ImprimeInvCartelasPartida(tPartida partida);
void JogaPartida(tPartida partida);

int main()
{
    tPartida partida;
    int qtdPartidas, i;
    partida = LeCartelasPartida();
    scanf("%d", &qtdPartidas);
    for (i = 0; i < qtdPartidas; i++)
    {
        if (i != 0)
            printf("\n");
        printf("PARTIDA %d\n", i + 1);
        partida = ResetaPartida(partida);
        JogaPartida(partida);
    }
    return 0;
}

tCartela LeCartela()
{
    int i = 0;
    int j = 0;
    tCartela cartela;
    scanf("%d %d", &cartela.id, &cartela.len);
    for (j = 0; j < cartela.len; j++)
        for (i = 0; i < cartela.len; i++)
            scanf("%3d", &cartela.numerosIniciais[i][j]);
    return cartela;
}

void ImprimeCartela(tCartela cartela)
{
    int i = 0;
    int j = 0;
    printf("ID:%d\n", cartela.id);
    for (i = 0; i < cartela.len; i++)
        for (j = 0; j < cartela.len; j++)
        {
            printf("%.3d", cartela.numerosIniciais[i][j]);
            if (j < cartela.len - 1)
                printf("|");
            else
                printf("\n");
        }
}

tPartida LeCartelasPartida()
{
    tPartida partida;
    int i = 0;
    scanf("%d", &partida.len);
    for (i = 0; i < partida.len; i++)
        partida.cartelas[i] = LeCartela();
    return partida;
}

void ImprimeInvCartelasPartida(tPartida partida)
{
    int i = 0;
    for (i = partida.len - 1; i >= 0; i--)
        ImprimeCartela(partida.cartelas[i]);
}

tPartida ResetaPartida(tPartida partida)
{
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < partida.len; i++)
        for (j = 0; j < partida.cartelas[i].len; j++)
            for (k = 0; k < partida.cartelas[i].len; k++)
                partida.cartelas[i].numerosMarcados[j][k] = 0;
    return partida;
}

tCartela MarcaCartela(tCartela cartela, int numero)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < cartela.len; i++)
        for (j = 0; j < cartela.len; j++)
            if (cartela.numerosIniciais[i][j] == numero)
                cartela.numerosMarcados[i][j] = 1;
    return cartela;
}

int VenceuCartela(tCartela cartela)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < cartela.len; i++)
        for (j = 0; j < cartela.len; j++)
        {
            if (cartela.numerosMarcados[i][j] == 1)
                continue;
            return 0;
        }
    return 1;
}

void JogaPartida(tPartida partida)
{
    int numeros[MAX_NUMEROS];
    int i = 0;
    int j = 0;
    int alguemVenceu = 0;
    for (i = 0; 1; i++)
    {
        scanf("%d", &numeros[i]);
        if (numeros[i] == -1)
            break;
    }
    for (i = 0; numeros[i] != -1 && !alguemVenceu; i++)
    {
        for (j = 0; j < partida.len; j++)
        {
            partida.cartelas[j] = MarcaCartela(partida.cartelas[j], numeros[i]);
            if (!VenceuCartela(partida.cartelas[j]))
                continue;
            if (!alguemVenceu)
            {
                printf("COM VENCEDOR\n");
                alguemVenceu = 1;
            }
            ImprimeCartela(partida.cartelas[j]);
        }
    }
    if (!alguemVenceu)
        printf("SEM VENCEDOR\n");
}
