//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct      s_list
//{
//    int             data;
//    struct s_list   *next;
//}                   t_list;
//
//typedef struct      s_lst
//{
//    struct s_list  *pointer;
//    struct s_lst   *next;
//}                   t_lst;
//
//int		ft_check(t_list *start, t_lst *mas)
//{
//    t_lst	*p;
//
//    p = mas;
//    while (p != NULL)
//    {
//        if (p->pointer == start)
//            return (1);
//        p = p->next;
//    }
//    return (0);
//}
//
//void    ft_add(t_lst **mas, t_list *start)
//{
//    t_lst   *new;
//
//    new = malloc(sizeof(new));
//    new->pointer = start;
//    new->next = *mas;
//    *mas = new;
//
//}
//
//int		cycle_detector(const t_list *list)
//{
//    t_list	*start;
//    t_lst   *mas;
//
//    mas = malloc(sizeof(mas));
//    mas->next = NULL;
//    if (!list)
//        return (0);
//    mas->pointer = (t_list*)list;
//    start = (t_list*)list;
//    while (start->next)
//    {
//        start = start->next;
//        if (ft_check(start, mas) == 1)
//            return (1);
//        ft_add(&mas, start);
//    }
//    return (0);
//}
//int     main(void)
//{
//    t_list  *l1;
//    t_list  *l2;
//    t_list  *l3;
//    t_list  *l4;
//    t_list  *l5;
//    t_list  *l6;
//
//    l1 = malloc(sizeof(l1));
//    l2 = malloc(sizeof(l1));
//    l3 = malloc(sizeof(l1));
//    l4 = malloc(sizeof(l1));
//    l5 = malloc(sizeof(l1));
//    l6 = malloc(sizeof(l1));
//
//    l1->next = l2;
//    l2->next = l3;
//    l3->next = l4;
//    l4->next = l5;
//    l5->next = l6;
//    l6->next = NULL;
//    printf("%i\n", cycle_detector(l1));
//    return (0);
//}


#include <stdio.h>
#include <stdlib.h>

typedef struct      s_list
{
    int             data;
    struct s_list   *next;
}                   t_list;

typedef struct      s_lst
{
    struct s_list  *pointer;
    struct s_lst   *next;
}                   t_lst;

int		ft_check(t_list *start, t_list **mas, int i)
{
    int     j;

    j = 0;
    while (j < i)
    {
        if (mas[j] == start)
            return (1);
        j++;
    }
    return (0);
}

int		cycle_detector(const t_list *list)
{
    t_list	*start;
    t_list   **mas;
    int     i;

    i = 0;
    mas = malloc(sizeof(t_list*) * 200);
    if (!list)
        return (0);
    mas[i++] = (t_list*)list;
    start = (t_list*)list;
    while (start->next)
    {
        start = start->next;
        if (ft_check(start, mas, i) == 1)
            return (1);
        mas[i++] = start;
    }
    return (0);
}
int     main(void)
{
    t_list  *l1;
    t_list  *l2;
    t_list  *l3;
    t_list  *l4;
    t_list  *l5;
    t_list  *l6;

    l1 = malloc(sizeof(l1));
    l2 = malloc(sizeof(l1));
    l3 = malloc(sizeof(l1));
    l4 = malloc(sizeof(l1));
    l5 = malloc(sizeof(l1));
    l6 = malloc(sizeof(l1));

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l5;
    l6->next = NULL;
    printf("%i\n", cycle_detector(l1));
    return (0);
}
