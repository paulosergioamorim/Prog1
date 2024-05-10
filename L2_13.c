#include <stdio.h>

int is_lower_letter(char letter);

int main(int argc, char const *argv[])
{
    char c = 0;

    while (!(c == '?' || c == '!' || c == '.'))
    {
        scanf("%c", &c);

        if (is_lower_letter(c))
            c += 'A' - 'a';

        printf("%c", c);
    }

    return 0;
}

int is_lower_letter(char letter)
{
    return 'a' <= letter && letter <= 'z';
}
