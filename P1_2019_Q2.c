#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 0;
    int num2 = 0;
    char op = 0;
    int resto = 0;
    scanf("%d %c %d", &num1, &op, &num2);
    switch (op)
    {
    case '+':
        printf("SOMA:%d", num1 + num2);
        break;
    case '-':
        printf("SUB:%d", num1 - num2);
        break;
    case '*':
        printf("MULT:%d", num1 * num2);
        break;
    case '/':
        resto = num1 % num2;
        printf("DIV:%d", num1 / num2);
        if (resto != 0)
            printf(", RESTO:%d", resto);
        break;
    default:
        break;
    }
    return 0;
}
