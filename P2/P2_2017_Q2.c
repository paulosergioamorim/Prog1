#include <stdio.h>

int EhIgual(int a, int b);
int InverteNumero(int num);

int main(int argc, char const *argv[])
{
    int count = 0;
    int num = 0;
    char c = ' ';

    while (c == ' ')
    {
        scanf("%d%c", &num, &c);

        if (EhIgual(num, InverteNumero(num)))
            count++;
    }

    printf("COUNT:%d", count);

    return 0;
}

int EhIgual(int a, int b)
{
    return a == b;
}

int InverteNumero(int num)
{
    int invertedNum = 0;

    for (num; num != 0; num /= 10)
    {
        invertedNum *= 10;
        invertedNum += num % 10;
    }

    return invertedNum;
}
