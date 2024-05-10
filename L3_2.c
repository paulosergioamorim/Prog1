#include <stdio.h>

float sum(float x, float y)
{
    return x + y;
}

float sub(float x, float y)
{
    return x - y;
}

float mul(float x, float y)
{
    return x * y;
}

float div(float x, float y)
{
    return x / y;
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
            result = sum(result, number);
            break;
        case '-':
            result = sub(result, number);
            break;
        case '*':
            result = mul(result, number);
            break;
        case '/':
            result = div(result, number);
            break;
        }
    }

    printf("%.2f", result);

    return 0;
}
