#include <stdio.h>

int main()
{
  int qtd = 0;
  int i = 0;
  scanf("%d", &qtd);

  if (qtd == 2)
  {
    printf("%d ", qtd);
    return 0;
  }

  for (i = 2; i <= qtd; i++)
  {
    int count = 0;
    int j = 0;
    for (j = 1; j <= i; j++)
      if (i % j == 0)
        count++;
    if (count == 2)
      printf("%d ", i);
  }

  return 0;
}