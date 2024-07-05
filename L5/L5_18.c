#include <stdio.h>

void mul_matrix(int l1, int c1, int l2, int c2, int matrix1[l1][c1], int matrix2[l2][c2], int result[l1][c2]);
void read_matrix(int l, int c, int matrix[l][c]);
void print_matrix(int l, int c, int matrix[l][c]);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int l1 = 0;
        int c1 = 0;
        scanf("%d %d", &c1, &l1);
        int matrix1[l1][c1];
        read_matrix(l1, c1, matrix1);
        int l2 = 0;
        int c2 = 0;
        scanf("%d %d", &c2, &l2);
        int matrix2[l2][c2];
        read_matrix(l2, c2, matrix2);
        if (c1 != l2)
        {
            printf("IMPOSSIVEL\n\n");
            continue;
        }
        int result[l1][c2];
        mul_matrix(l1, c1, l2, c2, matrix1, matrix2, result);
        print_matrix(l1, c2, result);
    }
    return 0;
}

void mul_matrix(int l1, int c1, int l2, int c2, int matrix1[l1][c1], int matrix2[l2][c2], int result[l1][c2])
{
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < l1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            int sum = 0;
            for (k = 0; k < c1; k++)
                sum += matrix1[i][k] * matrix2[k][j];
            result[i][j] = sum;
        }
    }
}

void read_matrix(int l, int c, int matrix[l][c])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &matrix[i][j]);
}

void print_matrix(int l, int c, int matrix[l][c])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%d", matrix[i][j]);
            if (j < c - 1)
                printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}
