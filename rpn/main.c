#include <stdlib.h>
#include <stdio.h>

typedef struct		s_list
{
	long long int	data;
	struct s_list	*next;
}					t_list;

int		ft_plus(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return (0);
	(*lst)->next->data = (*lst)->data + (*lst)->next->data;
	*lst = (*lst)->next;
	return (1);
}

int		ft_minus(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return (0);
	(*lst)->next->data = (*lst)->next->data - (*lst)->data;
	*lst = (*lst)->next;
	return (1);
}

int		ft_mnozh(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return (0);
	(*lst)->next->data = (*lst)->data * (*lst)->next->data;
	*lst = (*lst)->next;
	return (1);
}

int		ft_dil(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return (0);
	if ((*lst)->data == 0)
		return (0);
	(*lst)->next->data = (*lst)->next->data / (*lst)->data;
	*lst = (*lst)->next;
	return (1);
}

int		ft_ost(t_list **lst)
{
	if (!(*lst) || !((*lst)->next))
		return (0);
	if ((*lst)->data == 0)
		return (0);
	(*lst)->next->data = (*lst)->next->data % (*lst)->data;
	*lst = (*lst)->next;
	return (1);
}

int		ft_do(t_list **lst, char p)
{
	if (p == '+')
		return (ft_plus(lst));
	else if (p == '-')
		return (ft_minus(lst));
	else if (p == '*')
		return (ft_mnozh(lst));
	else if (p == '/')
		return (ft_dil(lst));
	else if (p == '%')
		return (ft_ost(lst));
	else
		return (0);
}

char	*ft_add(t_list **lst, char *p)
{
	t_list	*new;

	new = malloc(sizeof(new));
	new->data = atoi(p);
	while (*p >= '0' && *p <= '9')
		p++;
	new->next = *lst;
	*lst = new;
	return (p);
}

char	*ft_make(char *p, t_list **list)
{
	while (*p)
	{
		while (*p == ' ')
			p++;
		if (*p >= '0' && *p <= '9')
			p = ft_add(list, p);
		else
		{
			if (ft_do(list, *p) == 0)
				break ;
			else
				p++;
		}
	}
	return (p);
}

int		ft_check(char *s)
{
	while (*s)
	{
		if (*s == '+' || *s == '-' || *s == '/' || *s == '%' || *s == '*')
			return (1);
		s++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	char	*p;
	t_list	*list;

	list = malloc(sizeof(list));
	list->next = NULL;
	if (ac == 2 && ft_check(av[1]))
	{
		p = av[1];
		list->data = atoi(p);
		while (*p >= '0' && *p <= '9')
			p++;
		p = ft_make(p, &list);
		if (*p == '\0' && !(list->next))
			printf("%lli\n", list->data);
		else
			printf("Error\n");
	}
	else
		printf("Error\n");
	return (0);
}
