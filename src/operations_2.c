#include "push_swap.h"

static void	revrotate_one(t_list **lst)
{
    t_list	*tmp;

    if (!lst || !*lst || !(*lst)->next)
		return;
    tmp = *lst;
    while (tmp->next->next)
        tmp = tmp->next;
    ft_lstadd_front(lst, tmp->next);
    tmp->next = NULL;
}

void    reverse_rotate_r(t_list **a, t_list **b)
{
    revrotate_one(a);
    revrotate_one(b);
    ft_printf("rrr\n");
}

static void   rotate_one(t_list **lst)
{
    t_list  *tmp;

    if (!lst || !*lst || !(*lst)->next)
        return;
    tmp = *lst;
    *lst = (*lst)->next;
    tmp->next = NULL;
    ft_lstadd_back(lst, tmp);
}

void    rotate_r(t_list **a, t_list **b)
{
    rotate_one(a);
    rotate_one(b);
    ft_printf("rr\n");
}
