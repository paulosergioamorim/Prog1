#include <stdio.h>

#define MAX_LENGTH 7

typedef struct
{
    int id;
    int len;
    int numeros[MAX_LENGTH][MAX_LENGTH];
} tCartela;

tCartela LeCartela();
void ImprimeCartela(tCartela cartela);

int main()
{
    tCartela cartela;
    cartela = LeCartela();
    ImprimeCartela(cartela);
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
