/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:39:06 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/05 17:40:29 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char lstname)
{
	t_list	*temp;

	temp = *lst;
	if (lst && (*lst)->next != NULL)
	{
		*lst = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)->next = temp;
	}
	ft_printf("s%c\n", lstname);
}

void	push(t_list **src, t_list **dest, char lstname)
{
	t_list	*temp;

	if (*src)
	{
		temp = *src;
		(*src) = (*src)->next;
		temp->next = *dest;
		*dest = temp;
	}
	ft_printf("p%c\n", lstname);
}

void	rotate(t_list **lst, char lstname)
{
	t_list	*temp;

	temp = *lst;
	ft_lstadd_back(lst, temp);
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_printf("r%c\n", lstname);
}

void	reverse_rotate(t_list **lst, char lstname)
{
	t_list	*temp;

	temp = *lst;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	ft_lstadd_front(lst, temp->next);
	temp->next = NULL;
	ft_printf("rr%c\n", lstname);
}
