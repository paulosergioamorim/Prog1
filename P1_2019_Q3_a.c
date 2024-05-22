#include <stdio.h>

int is_number(char c);
int is_letter(char c);

int main(int argc, char const *argv[])
{
    char l1 = 0;
    char l2 = 0;
    char l3 = 0;
    char n1 = 0;
    char n2 = 0;
    char n3 = 0;
    char n4 = 0;
    scanf("%c%c%c-%c%c%c%c", &l1, &l2, &l3, &n1, &n2, &n3, &n4);

    if ((!is_letter(l1) || !is_letter(l2) || !is_letter(l3)) && (!is_number(n1) || !is_number(n2) || !is_number(n3) || !is_number(n4)))
        printf("Codigo invalido!Problema nas letras e nos numeros!");
    else if (!is_letter(l1) || !is_letter(l2) || !is_letter(l3))
        printf("Codigo invalido!Problema nas letras!");
    else if (!is_number(n1) || !is_number(n2) || !is_number(n3) || !is_number(n4))
        printf("Codigo invalido!Problema nos numeros!");
    else
        printf("Codigo valido!");
}

int is_number(char c)
{
    return '0' <= c && c <= '9';
}

int is_letter(char c)
{
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}
