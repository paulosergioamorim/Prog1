#include <stdio.h>

int main(int argc, char const *argv[])
{
    char f[100];
    char new_f[100];
    scanf("%s", f);
    size_t i = 0;

    for (i = 0; i < sizeof(f); i++)
    {
        new_f[i] = f[i];
        if (new_f[i] == ' ')
            new_f[i] == '_';
        if (new_f[i] == '?' || new_f[i] == '!' || new_f[i] == '.')
            break;
    }

    printf("RESP:%s", new_f);
    return 0;
}
