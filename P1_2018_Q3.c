#include <stdio.h>

void print_result(char a, char b);
int is_valid_code(char a, char b, char c);
int is_number(char c);
int reverse(char c);
int is_upper_letter(char c);
int is_lower_letter(char c);

int main(int argc, char const *argv[])
{
    char a = 0;
    char b = 0;
    char c = 0;
    char d = 0;
    char e = 0;
    char f = 0;
    scanf("%c%c%c %c%c%c", &a, &b, &c, &d, &e, &f);

    if (!is_valid_code(a, b, c) || !is_valid_code(d, e, f))
        printf("Codigo invalido!\n");
    else
    {
        print_result(a, d);
        print_result(b, e);
        print_result(c, f);
        printf("\n");
    }

    return 0;
}

void print_result(char a, char b)
{
    if (a == b)
        printf("I");
    else if (a + 32 == b || a - 32 == b)
        printf("C");
    else
        printf("D");
}

int is_valid_code(char a, char b, char c)
{
    return is_number(a) && is_lower_letter(b) && reverse(c);
}

int is_number(char c)
{
    return '0' <= c && c <= '9';
}

int reverse(char c)
{
    return is_upper_letter(c) || is_lower_letter(c);
}

int is_upper_letter(char c)
{
    return 'A' <= c && c <= 'Z';
}

int is_lower_letter(char c)
{
    return 'a' <= c && c <= 'z';
}
