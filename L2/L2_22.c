#include <stdio.h>

int main(int argc, char const *argv[])
{   
    int n = 0;
    scanf("%d", &n);

    while (n >= 10)
    {
        int u = n % 10;
        int d = n / 10 % 10;
        int c = n / 100 % 10;
        int m = n / 1000 % 10;
        int dm = n / 10000 % 10;
        n = u + d + c + m + dm; 
    }

    printf("RESP:%d", n);
    
    return 0;
}