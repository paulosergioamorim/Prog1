#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0;
    int i = 0;
    int max = 0;
    int min = 0;
    int even =0;
    int odd = 0;
    int sum = 0;
    double avg = 0;
    scanf("%d", &n);
    int numbers[n];

    for (i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
        sum += numbers[i];
        max = (numbers[i] > max) ? numbers[i] : max;
        min = (numbers[i] < min || i == 0) ? numbers[i] : min;
        if (numbers[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    avg = (float)sum / n;

    printf("%d %d %d %d %.6f", max, min, even, odd, avg);

    return 0;
}
