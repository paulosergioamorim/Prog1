#include <stdio.h>

#define MAX_CARTELA 7
#define MAX_PARTIDA 100

typedef struct
{
    int id;
    int len;
    int numeros[MAX_CARTELA][MAX_CARTELA];
} tCartela;

typedef struct
{
    int len;
    tCartela cartelas[MAX_PARTIDA];
} tPartida;

tPartida LeCartelasPartida();
tCartela LeCartela();
void ImprimeCartela(tCartela cartela);
void ImprimeInvCartelasPartida(tPartida partida);

int main()
{
    tPartida partida;
    partida = LeCartelasPartida();
    ImprimeInvCartelasPartida(partida);
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
            scanf("%3d", &cartela.numeros[i][j]);
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
            printf("%.3d", cartela.numeros[i][j]);
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
