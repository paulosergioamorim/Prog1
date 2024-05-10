#include <stdio.h>

typedef struct
{
    int codigo;
    float preco;
    int estoque;
} tProduto;

tProduto LeProduto();
int EhProduto1MaiorQ2(tProduto p1, tProduto p2);
int EhProduto1MenorQ2(tProduto p1, tProduto p2);
int TemProdutoEmEstoque(tProduto p);
void ImprimeProduto(tProduto p);

int main(int argc, char const *argv[])
{
    int i = 0;
    int n = 0;
    scanf("%d", &n);

    tProduto maiorProduto = {0, 0, 0};
    tProduto menorProduto = {0, 2e10, 0};

    for (i = 0; i < n; i++)
    {
        tProduto produto = LeProduto();

        if (!TemProdutoEmEstoque(produto))
            printf("FALTA:COD %d, PRE %.2f, QTD %d\n", produto.codigo, produto.preco, produto.estoque);

        if (EhProduto1MaiorQ2(produto, maiorProduto))
            maiorProduto = produto;

        if (EhProduto1MenorQ2(produto, menorProduto))
            menorProduto = produto;
    }

    printf("MAIOR:COD %d, PRE %.2f, QTD %d\n", maiorProduto.codigo, maiorProduto.preco, maiorProduto.estoque);
    printf("MENOR:COD %d, PRE %.2f, QTD %d\n", menorProduto.codigo, menorProduto.preco, menorProduto.estoque);

    return 0;
}

tProduto LeProduto()
{
    tProduto produto = {0, 0, 0};
    scanf("%d;%f;%d", &produto.codigo, &produto.preco, &produto.estoque);
    return produto;
}

int EhProduto1MaiorQ2(tProduto p1, tProduto p2)
{
    return p1.preco > p2.preco;
}

int EhProduto1MenorQ2(tProduto p1, tProduto p2)
{
    return EhProduto1MaiorQ2(p2, p1);
}

int TemProdutoEmEstoque(tProduto p)
{
    return p.estoque > 0;
}

void ImprimeProduto(tProduto p)
{
}
