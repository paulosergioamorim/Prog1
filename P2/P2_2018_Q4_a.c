#include <stdio.h>

int ReduzInteiro(int n);
int MontaSenha(int senha, int dig);
int ReduzCodigo();

int main(int argc, char const *argv[])
{
    int senha = 0;
    char c = 0;

    while (c != '.')
    {
        scanf("%c", &c);

        if (c == '(')
        {
            int dig = ReduzCodigo();
            if (dig == -1)
                printf("[ERRO]");
            else
            {
                printf("[%d]", dig);
                senha = MontaSenha(senha, dig);
            }

            scanf("%*[)]");
        }
        else
            printf("%c", c);
    }
    printf(" SENHA:%d\n", senha);
    return 0;
}

int ReduzInteiro(int n)
{
    int c = 0;
    for (c; n >= 10; c = 0)
    {
        for (n; n != 0; n /= 10)
            c += n % 10;
        n = c;
    }
    return n;
}

int MontaSenha(int senha, int dig)
{
    return senha * 10 + dig;
}

int ReduzCodigo()
{
    int n = 0;
    int i = 0;
    char c = 0;
    for (i; 1; i++)
    {
        scanf("%c", &c);
        if (c == ')')
        {
            if (i == 0)
                return -1;
            return n;
        }
        n += c - '0';
        n = ReduzInteiro(n);
    }
    return n;
}
