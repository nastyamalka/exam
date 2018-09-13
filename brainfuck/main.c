#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int  c, char **a)
{
	if (c == 1)
		return (0);
	char *str = "+++++[>++++[>++++H>+++++i<<-]>>>++<<<<-]>>--------.>+++++.>.";
	//char *str = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
	//char *str = "[qqq][]d[]df[[]]g[]hdf";
	char arr[16384]  = {0};
	char *p;
	int i;
	int	bh = 0;
	
	i = 0;
	p = str;
	while (*p)
	{
		bh = 0;
		if (*p == '+')
			arr[i]++;
		else if (*p == '-')
			arr[i]--;
		else if (*p == '<')
			i--;
		else if (*p == '>')
			i++;
		else if (*p == '[')
		{
			if (arr[i] == 0)
			{
				bh++;
				while (*p && bh != 0)
				{
					p++;	
					if (*p == '[')
						bh++;
					else if (*p == ']')
						bh--;
				}
			}
		}
		else if (*p == ']')
		{
			if (arr[i] != 0)
			{
				bh++;
				while (p != str && bh != 0)
				{
					p--;	
					if (*p == '[')
						bh--;
					else if (*p == ']')
						bh++;
				}
			}			
		}	
		else if (*p == '.')
			write(1, &arr[i], 1);
		if(*p)
			p++;
	}
	return (0);
}
