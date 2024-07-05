#include <stdio.h>

float FazOperacao(float num1, float num2, char op);
float ResolveExpressao();

int main(int argc, char const *argv[])
{
    float maior = 0;
    char c = 0;

    while (c != '.')
    {
        scanf("%c", &c);

        if (c == '(')
        {
            float valor = ResolveExpressao();
            printf("%.2f", valor);

            if (valor > maior)
                maior = valor;

            continue;
        }

        printf("%c", c);
    }

    printf(" MAIOR:%.2f", maior);
}

float FazOperacao(float num1, float num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        return num1 / num2;
    }
}

float ResolveExpressao()
{
    float num1 = 0;
    float num2 = 0;
    char op = 0;

    scanf("%f", &num1);

    while (scanf("%f %c", &num2, &op) == 2)
        num1 = FazOperacao(num1, num2, op);

    scanf("%*[)]");

    return num1;
}
