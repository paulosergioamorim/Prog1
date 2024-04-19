#include <stdio.h>

void sum(float *acc, float cur)
{
    *acc += cur;
}

void sub(float *acc, float cur)
{
    *acc -= cur;
}

void mul(float *acc, float cur)
{
    *acc *= cur;
}

void div(float *acc, float cur)
{
    *acc /= cur;
}

int main(int argc, char const *argv[])
{
    float number = 0;
    char operation = 0;
    float result = 0;

    scanf("%f", &result);

    while (scanf("%f %c", &number, &operation) == 2)
    {
        switch (operation)
        {
        case '+':
            sum(&result, number);
            break;
        case '-':
            sub(&result, number);
            break;
        case '*':
            mul(&result, number);
            break;
        case '/':
            div(&result, number);
            break;
        }
    }

    printf("%.2f", result);

    return 0;
}
