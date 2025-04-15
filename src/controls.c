#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (lst && (*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)->next = temp;
	}
}

void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src)
	{
		temp = *src;
		(*src) = (*src)->next;
		temp->next = *dest;
		*dest = temp;
	}
}

void	rotate_a(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	ft_lstadd_back(lst, temp);
	*lst = (*lst)->next;
	temp->next = NULL;
}

void	reverse_rotate_a(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	ft_lstadd_front(lst, temp->next);
	temp->next = NULL;
}