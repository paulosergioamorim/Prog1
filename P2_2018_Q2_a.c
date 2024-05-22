#include <stdio.h>

int EhIgual(int a, int b);
int MaiorDigito(int num);

int main(int argc, char const *argv[])
{
    int soma = 0;
    int num1 = 0;
    int num2 = 0;
    while (getchar() == '(')
    {
        scanf("%d,%d)", &num1, &num2);
        if (EhIgual(MaiorDigito(num1), MaiorDigito(num2)))
            soma++;
    }
    printf("COUNT:%d", soma);
    return 0;
}

int EhIgual(int a, int b)
{
    return a == b;
}

int MaiorDigito(int num)
{
    int maior = 0;

    for (num; num != 0; num /= 10)
    {
        int digito = num % 10;
        if (digito > maior)
            maior = digito;
    }

    return maior;
}
