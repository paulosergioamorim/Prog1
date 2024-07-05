#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_str_equal(char str1[], char str2[]);
bool is_letter_equal(char c1, char c2);
void set_char_in_str(char c, char str[]);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    char str1[400] = "";
    char str2[400] = "";
    char str3[400] = "";
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s %s", str1, str2);
        strncpy(str3, "", strlen(str3));
        int pJ = 0;
        for (k = 0; k < strlen(str1); k++)
        {
            for (j = 0; j < strlen(str2); j++)
            {
                char c1 = str1[k];
                char c2 = str2[j];
                if (is_letter_equal(c1, c2))
                {
                    set_char_in_str(c2, str3);
                    for (l = pJ; l <= j; l++)
                        str2[l] = '_';
                    pJ = j;
                    break;
                }
            }
        }
        if (is_str_equal(str1, str3))
            printf("PODE!\n");
        else
            printf("NAO PODE!\n");
    }
    return 0;
}

bool is_str_equal(char str1[], char str2[])
{
    int i = 0;
    if (strlen(str1) != strlen(str2))
        return false;
    for (i = 0; str1[i] != '\0'; i++)
        if (!is_letter_equal(str1[i], str2[i]))
            return false;
    return true;
}

bool is_letter_equal(char c1, char c2)
{
    return c1 == c2 || c1 + 32 == c2 || c1 - 32 == c2;
}

void set_char_in_str(char c, char str[])
{
    int len = strlen(str);
    str[len] = c;
}
