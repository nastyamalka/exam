#include <unistd.h>

int 	ft_is_open(char c)
{
	if (c == '(')
		return (1);
	else if (c == '{')
		return (1);
	else if (c == '[')
		return (1);
	else
		return (0);
}

int 	ft_is_close(char c)
{
	if (c == ')')
		return (1);
	else if (c == '}')
		return (1);
	else if (c == ']')
		return (1);
	else
		return (0);
}

int 	ft_good(char otkr, char zakr)
{
	if (otkr == '(' && zakr == ')')
		return (1);
	if (otkr == '[' && zakr == ']')
		return (1);
	if (otkr == '{' && zakr == '}')
		return (1);
	else
		return (0);
}

int main(int ac, char **av)
{
	char *p_otkr;
	char *p_zakr;
	char *start;
	int m;
	int i;

	i = 1;
	if (ac == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < ac) {
		m = 1;
		start = av[i];
		p_zakr = start;
		p_otkr = NULL;
		while (*p_zakr != '\0' && m) {
			while (*(p_zakr) && !ft_is_close(*p_zakr))
				p_zakr++;
			if (p_otkr == NULL && *p_zakr == '\0')
				break ;
			p_otkr = p_zakr;
			while (p_otkr-- != start)
				if (ft_is_open(*p_otkr) == 1)
					break;
			if (!ft_good(*p_otkr, *p_zakr))
				m = 0;
			else {
				*p_otkr = '0';
				*p_zakr = '0';
			}
			p_zakr++;
		}
		(m == 0) ? write(1, "Error\n", 6) : write(1, "Ok\n", 3);
		i++;
	}
	return (0);
}
