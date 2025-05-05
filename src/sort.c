/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:39:13 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/05 17:39:14 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

short int	is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}

void	small_sort(t_list **a)
{
	if (is_sorted(*a))
		return ;
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		swap(a, 'a');
		rotate(a, 'a');
	}
	if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content)
		swap(a, 'a');
	if ((*a)->content < (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
		rotate(a, 'a');
	if ((*a)->content > (*a)->next->content
		&& (*a)->next->content < (*a)->next->next->content
		&& (*a)->content > (*a)->next->next->content)
		reverse_rotate(a, 'a');
	if ((*a)->content > (*a)->next->content
		&& (*a)->next->content > (*a)->next->next->content)
	{
		swap(a, 'a');
		reverse_rotate(a, 'a');
	}
}

void	move_to_b(t_list **a, t_list **b)
{
	int	median;
	int	i;

	i = 0;
	median = find_median(*a);
	while (i < (ft_lstsize(*a) / 2))
	{
		if ((*a)->index <= median)
		{
			push(a, b, 'b');
			i++;
		}
		else
			rotate(a, 'a');
	}
	while (ft_lstsize(*a) > 3)
	{
		push(a, b, 'b');
	}
	small_sort(a);
}

void	move_to_a(t_list **a, t_list **b)
{
	t_list	*cheapest;

	while (ft_lstsize(*b) != 0)
	{
		set_cost(*a);
		set_cost(*b);
		cheapest = get_cheapest(*a, *b);
		align_stacks(a, b, cheapest);
		push(b, a, 'a');
	}
}

void	last_rotate(t_list **a)
{
	t_list	*temp_a;
	int		position;

	temp_a = *a;
	position = 0;
	while (temp_a && temp_a->index != 1)
	{
		position++;
		temp_a = temp_a->next;
	}
	if (position <= ft_lstsize(*a) / 2)
	{
		while ((*a)->index != 1)
			rotate(a, 'a');
	}
	else
	{
		while ((*a)->index != 1)
			reverse_rotate(a, 'a');
	}
}
