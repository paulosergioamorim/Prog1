#include <stdio.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("Par");
    else
        printf("Impar");
    return 0;
}