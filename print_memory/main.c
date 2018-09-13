#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>



void	print_memory(const void *addr, size_t size)
{
 unsigned char *t = (unsigned char*) addr;
	int i;
	int k;
	int j;
 	i = size - 1;
	while (i >= 0)
	{
		if (t[i] != 0)
			break;
		i--;
	}
	k = i;
	j = 0;
	printf("I: %i\n\n", i);

	for (size_t i = 0; i < size ; i++)
	{
		if (printf("%x", t[i]) == 1)
			printf("0");
		if ( i % 2 != 0)
			printf(" ");
		if ((i+ 1) % 16 == 0)
		{
			while (j <= i )
			{
				if (j == k)
					printf("*");
				else printf(".");
				j++;
			}
			printf("\n");
		}
		//printf("\ni: %zu\n", i);
	}
if (i == size)
		{
			while (j <= i )
			{
				if (j == k)
					printf("*");
				else printf(".");
				j++;
			}
			printf("\n");
		}

}

int main(int  c, char **a)
{
	int i = 0;
	int	tab[10] = {0, 23, 150, 255, 12, 16,  21, 42};
	printf("\n%i\n\n",tab[9]);		          
	print_memory(tab, sizeof(tab));
	return (0);
}
