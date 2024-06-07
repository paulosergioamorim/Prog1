#include <stdio.h>

int reverse(char c);
int is_lower_letter(char c);
int is_upper_letter(char c);
int is_number(char c);
int is_alphanumeric(char c);
int is_alphanumerics_equal(char x, char y);

int main(int argc, char const *argv[])
{
    char a = 0;
    char b = 0;
    char c = 0;
    char d = 0;
    scanf("%c%c %c%c", &a, &b, &c, &d);

    if (!is_alphanumeric(a) || !is_alphanumeric(b) || !is_alphanumeric(c) || !is_alphanumeric(d))
        printf("Invalido");
    else if (is_alphanumerics_equal(a, c) && is_alphanumerics_equal(b, d))
        printf("IGUAIS");
    else
        printf("DIFERENTES");
}

int reverse(char c)
{
    return is_lower_letter(c) || is_upper_letter(c);
}

int is_lower_letter(char c)
{
    return 'a' <= c && c <= 'z';
}

int is_upper_letter(char c)
{
    return 'A' <= c && c <= 'Z';
}

int is_number(char c)
{
    return '0' <= c && c <= '9';
}

int is_alphanumeric(char c)
{
    return reverse(c) || is_number(c);
}

int is_alphanumerics_equal(char x, char y)
{
    if (is_number(x) || (is_lower_letter(x) && is_lower_letter(y)) || (is_upper_letter(x) && is_upper_letter(y)))
        return x == y;
    if (is_lower_letter(x))
        return x == y + 32;
    return x == y - 32;
}
