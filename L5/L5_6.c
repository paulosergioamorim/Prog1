#include <stdio.h>

int main()
{
	int nA = 0;
	int nB = 0;
	int i = 0;
	int j = 0;
	scanf("%d", &nA);
	int listA[nA];

	for (i; i < nA; i++)
		scanf("%d", &listA[i]);

	scanf("%d", &nB);
	int listB[nB];

	for (i = 0; i < nB; i++)
		scanf("%d", &listB[i]);

	int isListAinListB = 1;
	int isAnyElementAinListB = 0;

	for (i = 0; i < nA; i++)
	{
		int occurrences = 0;
		for (j = 0; j < nB; j++)
		{
			if (listB[j] != listA[i])
				continue;
			occurrences++;
			isAnyElementAinListB = 1;
		}
		if (occurrences == 0)
			isListAinListB = 0;
	}

	if (isListAinListB)
		printf("TODOS");
	else if (isAnyElementAinListB)
		printf("PARCIAL");
	else
		printf("NENHUM");

	return 0;
}
