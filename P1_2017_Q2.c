#include <stdio.h>

int is_man(int x);
int is_woman(int x);
int is_person(int x);

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    if (!is_person(x) || !is_person(y))
        printf("Invalido");
    else if (is_man(x) && is_man(y))
    {
        if (x == y)
            printf("Um homem");
        else
            printf("Par de homens");
    }
    else if (is_woman(x) && is_woman(y))
    {
        if (x == y)
            printf("Uma mulher");
        else
            printf("Par de mulheres");
    }
    else
        printf("Um casal");

    return 0;
}

int is_man(int x)
{
    return 1 <= x && x <= 5;
}

int is_woman(int x)
{
    return 6 <= x && x <= 10;
}

int is_person(int x)
{
    return is_man(x) || is_woman(x);
}
