#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char checkboard[8][8];
    char key = '\0';
    int x = 0;
    int y = 0;

    while (1)
    {
        printf("\nMenu:\nR - Rei\nT - Torre\nQ - Sair\nEscolha uma opcao: \n");
        scanf(" %c", &key);

        if (key == 'Q')
            return 0;

        if (key != 'T' && key != 'R')
        {
            printf("Opcao invalida! Escolha novamente.\n");
            continue;
        }

        printf("Indique a coordenada (X,Y):\n");
        scanf("%d %d", &x, &y);
        x--;
        y--;
        
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (key == 'T')
                    checkboard[i][j] = (x == i || y == j) ? 'X' : '-';
                else
                    checkboard[i][j] = (abs(x - i) <= 1 && abs(y - j) <= 1) ? 'X' : '-';
                printf("%c ", checkboard[i][j]);
            }
            printf("\n");
        }
    }
}
