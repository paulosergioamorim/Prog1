#include <stdio.h>

int main(int argc, char *argv[])
{
	int custo1 = 0;
	int custo2 = 0;
	int custo3 = 0;
	int soma = 0;
	int n = 0;

	scanf("%d %d %d", &custo1, &custo2, &custo3);
	scanf("%d", &n);

	for (n; n > 0; n--)
	{
		int tipo = 0;
		scanf("%d", &tipo);

		switch (tipo)
		{
		case 1:
			soma += custo1;
			break;
		case 2:
			soma += custo2;
			break;
		case 3:
			soma += custo3;
			break;
		}
	}

	printf("CUSTO:%d\n", soma);

	return 0;
}
