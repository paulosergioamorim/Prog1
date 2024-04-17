#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int nums[9] = {};
    char str[200] = "";
    int i = 0;

    for (i = 0; i < 9; i++)
        nums[i] = -1;

    for (i = 0; 1; i++)
        if (!scanf("%d", &nums[i]))
            break;

    scanf("%[^\n]", str);

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == '"')
            continue;

        if (str[i] != '%')
        {
            printf("%c", str[i]);
            continue;
        }

        i++;
        int j = str[i] - '0';

        if (j < 1 || j > nums[0])
        {
            printf("ERRO");
            continue;
        }

        printf("%d", nums[j]);
    }

    return 0;
}
