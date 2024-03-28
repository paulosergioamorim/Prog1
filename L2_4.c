#include <stdio.h>

int main(int argc, char const *argv[])
{
    int numbers[] = { };
    int i = 0;
    int j = 0;
    int n = -1;
    while (n != 0) {
        scanf("%d\n", &n);
        numbers[i] = n;
        
        i++;
    }
    
    return 0;
}
