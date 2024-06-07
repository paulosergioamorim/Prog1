#include <stdio.h>
#define WATER '1'
#define GROUND '0'

int count_ground(int l, int c, char matrix[l][c]);
int has_near_water(int l, int c, char matrix[l][c], int i, int j);
void read_matrix(int l, int c, char matrix[l][c]);
void copy_matrix(int l, int c, char matrix1[l][c], char matrix2[l][c]);
void simulate(int l, int c, char matrix[l][c], int h);

int main(int argc, char const *argv[])
{
    int h = 0;
    int l = 0;
    int c = 0;
    int count = 0;
    scanf("%d", &h);
    scanf("%d %d\n", &c, &l);
    char matrix[l][c];
    read_matrix(l, c, matrix);
    count = count_ground(l, c, matrix);
    printf("%d ", count);
    simulate(l, c, matrix, h);
    count = count_ground(l, c, matrix);
    printf("%d\n", count);
    return 0;
}

void read_matrix(int l, int c, char matrix[l][c])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
            scanf("%c", &matrix[i][j]);
        scanf("\n");
    }
}

void copy_matrix(int l, int c, char matrix1[l][c], char matrix2[l][c])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            matrix1[i][j] = matrix2[i][j];
}

void simulate(int l, int c, char matrix[l][c], int h)
{
    int i = 0;
    int j = 0;
    int k = 0;
    for (k = 0; k < h; k++)
    {
        char newMatrix[l][c];
        copy_matrix(l, c, newMatrix, matrix);
        for (i = 1; i < l - 1; i++)
            for (j = 1; j < c - 1; j++)
                if (has_near_water(l, c, matrix, i, j))
                    newMatrix[i][j] = WATER;
        copy_matrix(l, c, matrix, newMatrix);
    }
}

int count_ground(int l, int c, char matrix[l][c])
{
    int count = 0;
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            if (matrix[i][j] == GROUND)
                count++;
    return count;
}

int has_near_water(int l, int c, char matrix[l][c], int i, int j)
{
    char up = matrix[i - 1][j];
    char down = matrix[i + 1][j];
    char left = matrix[i][j - 1];
    char rigth = matrix[i][j + 1];
    return up == WATER || down == WATER || left == WATER || rigth == WATER;
}
