#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[100] = {};
    int pos = 0;
    int neg = 0;
    int sumPos = 0;
    int sumNeg = 0;
    size_t i = 0;

    for (i = 0; 1; i++)
    {
        char c = '\0';
        scanf("%d%c", &nums[i], &c);
        if (nums[i] >= 0) {
            pos++;
            sumPos += nums[i];
        } else {
            neg++;
            sumNeg += nums[i];
        }
        if (c != 32)
            break;
    }

    printf("%d %d %d %d", neg, pos, sumNeg, sumPos);

    return 0;
}
