#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;

    scanf("%d\n", &n);

    for (i = 0; i < n; i++)
    {
        while (!scanf(" -1"))
        {
            int id = 0;
            char sexo = '\0';
            int p1 = 0;
            int p2 = 0;
            int p3 = 0;
            scanf("%d %c %d %d %d", &id, &sexo, &p1, &p2, &p3);
        }
    }

    return 0;
}
