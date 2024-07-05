#include <stdio.h>

int is_lower_letter(char letter);

int main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;
	char c = 0;

	scanf("%d %d%*[ ]", &i, &j);

	while (c != '.')
	{
		scanf("%c", &c);

		if (is_lower_letter(c))
		{
			switch (i)
			{
			case 0:
				printf("Operacao invalida.");
				return 0;
			case 1:
				c += j % 26;
				if (!is_lower_letter(c))
					c += 'a' - 'z' - 1;
				break;
			case 2:
				c -= j % 26;
				if (!is_lower_letter(c))
					c += 'z' - 'a' + 1;
				break;
			default:
				printf("Operacao invalida.");
				return 0;
			}
		}

		printf("%c", c);
	}
}

int is_lower_letter(char letter)
{
	return 'a' <= letter && letter <= 'z';
}