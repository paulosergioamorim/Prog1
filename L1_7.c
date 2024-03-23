#include <stdio.h>

// Tc / 5 = (Tf - 32) / 9

int main()
{
	float temp = 0;
	char escala = ' ';
	scanf("%f %c", &temp, &escala);
	if (escala == 'C' || escala == 'c')
	{
		float f = (9 * temp / 5) + 32;
		printf("%.2f (F)", f);
		return 0;
	}
	float c = (temp - 32) * 5 / 9;
	printf("%.2f (C)", c);
	return 0;
}
