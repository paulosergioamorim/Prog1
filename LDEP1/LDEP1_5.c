#include <stdio.h>

int main()
{
	int a = 0, b = 0, i = 1, j = 1, mdc = 0, mmc = 0, limMDC = 0, limMMC = 0;

	scanf("%d %d", &a, &b);

	limMDC = (a > b) ? a : b;
	limMMC = a * b;

	for (i = 1; i <= limMDC; i++)
		if ((a % i == 0) && (b % i == 0))
			mdc = i;

	for (j = 1; j <= limMMC; j++)
		if ((j % a == 0) && (j % b == 0)) {
			mmc = j;
			break;
		}

	printf("%d %d", mdc, mmc);

	return 0;
}
