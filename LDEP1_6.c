#include <stdio.h>

int main()
{
	int l, c, i, j, soma, atual = 0;
	scanf("%d %d", &l, &c);

	for (i = 0; i < c; i++)
	{
		for (j = 0; j < l; j++)
		{
			scanf("%d", &atual);
			soma += atual;
		}
		printf("%d\n", soma);
	}

	printf("%d\n", soma);

	return 0;
}
