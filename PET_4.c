#include <stdio.h>
#include <math.h>

int length_of(int number);
int is_narcissist(int number);

int main(int argc, char const *argv[])
{
    int start = 0;
    int end = 0;
    scanf("%d %d", &start, &end);

    if (start < 0 || end < 0 || start > end)
    {
        printf("Intervalo invalido!\n");
        return 0;
    }

    for (int i = start; i <= end; i++)
        if (is_narcissist(i))
            printf("%d ", i);

    return 0;
}

int length_of(int number)
{
    int length = 0;

    for (number; number != 0; number /= 10)
        length++;

    return length;
}

int is_narcissist(int number)
{
    int sum = 0;
    int length = length_of(number);

    for (int copy = number; copy != 0; copy /= 10)
    {
        int digit = copy % 10;
        sum += pow(digit, length);
    }

    return sum == number;
}