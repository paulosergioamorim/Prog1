#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        int vec[m];
        for (j = 0; j < m; j++)
            scanf("%d", &vec[j]);
        for (j = 0; j < m; j++)
        {
            int count = 0;
            for (k = 0; k < m; k++)
                if (k != j && vec[k] > vec[j])
                    count++;
            printf("%d ", count);
        }
        printf("\n");
    }
    return 0;
}
