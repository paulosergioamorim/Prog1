#include <stdio.h>

int EhProduto(char prd);
int AcabaramOsProdutos(char prd);
int QtdDoProdutoMaisComprado();

int main(int argc, char const *argv[])
{
    int codigoMaior = 0;
    int quantidadeMaior = 0;

    while (1)
    {
        int codigo = 0;

        scanf("%d", &codigo);

        if (codigo == -1)
        {
            printf("CLIENT:%d QTD:%d", codigoMaior, quantidadeMaior);
            return 0;
        }

        int quantidade = QtdDoProdutoMaisComprado();

        if (quantidade <= quantidadeMaior)
            continue;

        quantidadeMaior = quantidade;
        codigoMaior = codigo;
    }
}

int EhProduto(char prd)
{
    return 'A' <= prd && prd <= 'Z';
}

int AcabaramOsProdutos(char prd)
{
    return prd == '0';
}

int QtdDoProdutoMaisComprado()
{
    int quantidadeMaior = 0;
    int quantidadeAtual = 0;
    char produtoMaior = 0;
    char produtoAtual = 0;

    while (1)
    {
        char produto = 0;
        scanf("%c", &produto);

        if (AcabaramOsProdutos(produto))
            return quantidadeMaior;

        if (!EhProduto(produto))
            continue;

        if (produto != produtoAtual)
        {
            quantidadeAtual = 0;
            produtoAtual = produto;
        }

        quantidadeAtual++;

        if (quantidadeAtual > quantidadeMaior)
        {
            quantidadeMaior = quantidadeAtual;
            produtoMaior = produto;
        }
    }
}
