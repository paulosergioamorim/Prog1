#include <stdio.h>
#include <string.h>

void reverse(int len, char words[len][501]);

int main(int argc, char const *argv[])
{
    char words[500][501];
    int len = 0;
    int i = 0;
    for (i = 0; i < 500; i++)
        scanf("%501[A-Za-z]%*[^A-Za-z]", words[i]);
    for (i = 0, len = 0; strlen(words[i]); i++, len++)
        ;
    reverse(len, words);
    for (i = 0; i < len; i++)
        printf(" %s", words[i]);
    printf(" ");

    return 0;
}

void reverse(int len, char words[len][501])
{
    int i = 0;
    char newWords[len][501];
    for (i = 0; i < len; i++)
        strcpy(newWords[i], words[len - i - 1]);
    for (i = 0; i < len; i++)
        strcpy(words[i], newWords[i]);
}