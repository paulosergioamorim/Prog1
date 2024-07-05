#include <stdio.h>
#include <math.h>
#include <limits.h>

int max(int size, int ptr[]);
int min(int size, int ptr[]);
float avg(int size, int ptr[]);
float standard_deviation(int size, int ptr[]);

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    float avarage = 0;
    int greaterThanOrEqualAvgCount = 0;
    int smallerThan70Count = 0;

    scanf("%d", &n);
    int ptr[n];

    for (i; i < n; i++)
        scanf("%d", &ptr[i]);

    avarage = avg(n, ptr);

    for (i = 0; i < n; i++)
    {
        if (ptr[i] > avarage)
            greaterThanOrEqualAvgCount++;
        if (ptr[i] < 70)
            smallerThan70Count++;
    }

    printf("MENOR:%d, MAIOR:%d, MEDIA:%.2f, STD:%.2f, ACIMA_MEDIA_CONC:%d, REPROV:%d", min(n, ptr), max(n, ptr), avarage, standard_deviation(n, ptr), greaterThanOrEqualAvgCount, smallerThan70Count);
}

int max(int size, int ptr[])
{
    int i = 0;
    int max = INT_MIN;

    for (i; i < size; i++)
        if (ptr[i] > max)
            max = ptr[i];

    return max;
}

int min(int size, int ptr[])
{
    int i = 0;
    int min = INT_MAX;

    for (i; i < size; i++)
        if (ptr[i] < min)
            min = ptr[i];

    return min;
}

float avg(int size, int ptr[])
{
    float avg = 0;
    int i = 0;

    for (i; i < size; i++)
        avg += ptr[i];

    avg /= size;

    return avg;
}

float standard_deviation(int size, int ptr[])
{
    float avarege = avg(size, ptr);
    float variance = 0;
    int i = 0;

    for (i = 0; i < size; i++)
        variance += pow(ptr[i] - avarege, 2);

    variance /= size;

    return sqrt(variance);
}
