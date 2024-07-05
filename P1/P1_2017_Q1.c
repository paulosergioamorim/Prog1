#include <stdio.h>

int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int div(int x, int y);
int do_operation(int x, int y, char c);
int is_operation(char c);

int main(int argc, char const *argv[])
{
    int x = 0;
    int y = 0;
    char c = 0;
    scanf("%d %d %c", &x, &y, &c);

    if (!is_operation(c))
    {
        printf("Invalido");
        return 0;
    }

    printf("RESP:%d", do_operation(x, y, c));
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

int do_operation(int x, int y, char c)
{
    switch (c)
    {
    case '+':
        return sum(x, y);
    case '-':
        return sub(x, y);
    case '*':
        return mul(x, y);
    case '/':
        return div(x, y);
    }
}

int is_operation(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}
