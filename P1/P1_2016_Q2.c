#include <stdio.h>

int fX(int a, int b, int x);

int main(int argc, char const *argv[])
{
    int a = 0;
    int b = 0;
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;
    int x3 = 0;
    int y3 = 0;
    int count = 0;

    scanf("%d %d %d %d %d %d %d %d", &a, &b, &x1, &y1, &x2, &y2, &x3, &y3);

    if (fX(a, b, x1) == y1)
        count++;
    if (fX(a, b, x2) == y2)
        count++;
    if (fX(a, b, x3) == y3)
        count++;

    if (count == 0)
        printf("Nenhum");
    if (count == 1)
        printf("Um");
    if (count == 2)
        printf("Dois");
    if (count == 3)
        printf("Todos");
}

int fX(int a, int b, int x)
{
    return a * x + b;
}
