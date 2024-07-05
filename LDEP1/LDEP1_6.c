#include <stdio.h>

int main()
{
	int l, c, i, j, total = 0, soma, atual = 0;
	scanf("%d %d", &l, &c);

	for (i = 0; i < l; i++)
	{
		for (j = 0; j < c; j++)
		{
			scanf("%d", &atual);
			soma += atual;
		}
		printf("%d\n", soma);
		total += soma;
		soma = 0;
	}

	printf("%d\n", total);

	return 0;
}
