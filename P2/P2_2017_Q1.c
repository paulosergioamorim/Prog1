#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int minNum = __INT_MAX__;
    int minPos = 0;
    scanf("%d", &n);

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++)
    {
        int num = 0;
        scanf("%d", &num);
        if (num < minNum)
        {
            minNum = num;
            minPos = i + 1;
        }
    }

    printf("POS:%d", minPos);

    return 0;
}
