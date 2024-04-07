#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	char s[100] = "";
	scanf("%d %d %[^.]", &i, &j, s);

	for (k = 0; k < strlen(s); k++)
	{
		if (s[k] >= 97 && s[k] <= 122)
		{
			if (i == 1)
			{
				s[k] += j % 26;
				if (s[k] > 122)
					s[k] -= 26;			
			}
			else if (i == 2)
			{
				s[k] -= j % 26;
				if (s[k] < 97)
					s[k] += 26;
			}
			else
			{
				printf("Operacao invalida.");
				return 0;
			}
		}
	}

	printf("%s.", s);

	return 0;
}
