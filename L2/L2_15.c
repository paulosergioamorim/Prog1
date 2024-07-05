#include <stdio.h>

int main(int argc, char const *argv[])
{
    int pos = 0;
    int neg = 0;
    int sumPos = 0;
    int sumNeg = 0;
    int i = 0;
    char c = 0;

    while (scanf("%d%c", &i, &c) > 0)
    {
        if (i > 0)
        {
            pos++;
            sumPos += i;
        }
        else if (i < 0)
        {
            neg++;
            sumNeg += i;
        }

        if (c == '\n' || c == '\0')
            break;
    }

    printf("%d %d %d %d", neg, pos, sumNeg, sumPos);

    return 0;
}
