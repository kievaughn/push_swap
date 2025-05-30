/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:39:15 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/08 15:07:53 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_nearest_higher(t_list *a, t_list *b_node)
{
	t_list	*temp_a;
	int		diff;
	int		smallest_diff;

	temp_a = a;
	smallest_diff = INT_MAX;
	b_node->nearest = 0;
	while (temp_a)
	{
		if (temp_a->index > b_node->index)
		{
			diff = temp_a->index - b_node->index;
			if (diff < smallest_diff)
			{
				smallest_diff = diff;
				b_node->nearest = temp_a->index;
			}
		}
		temp_a = temp_a->next;
	}
}

int	get_total_cost(t_list *a, t_list *b_node)
{
	t_list	*temp_a;

	temp_a = a;
	while (temp_a)
	{
		if (temp_a->index == b_node->nearest)
			return (b_node->cost_to_top + temp_a->cost_to_top);
		temp_a = temp_a->next;
	}
	return (INT_MAX);
}

static void	common_rotate(t_list **a, t_list **b, t_list *cheapest,
		t_list *temp_a)
{
	while (cheapest->cost_to_top > 0 && temp_a && temp_a->cost_to_top > 0
		&& cheapest->reverse == temp_a->reverse)
	{
		if (cheapest->reverse)
			reverse_rotate_r(a, b);
		else
			rotate_r(a, b);
		cheapest->cost_to_top--;
		temp_a->cost_to_top--;
	}
}

void	align_stacks(t_list **a, t_list **b, t_list *cheapest)
{
	t_list	*temp_a;

	temp_a = *a;
	while (temp_a && temp_a->index != cheapest->nearest)
		temp_a = temp_a->next;
	common_rotate(a, b, cheapest, temp_a);
	while (cheapest->cost_to_top > 0)
	{
		if (cheapest->reverse)
			reverse_rotate(b, 'b');
		else
			rotate(b, 'b');
		cheapest->cost_to_top--;
	}
	while (temp_a && temp_a->cost_to_top > 0)
	{
		if (temp_a->reverse)
			reverse_rotate(a, 'a');
		else
			rotate(a, 'a');
		temp_a->cost_to_top--;
	}
}

int	find_median(t_list *a)
{
	int		sum;
	int		i;
	t_list	*temp_a;

	sum = 0;
	i = 0;
	temp_a = a;
	while (temp_a)
	{
		sum += temp_a->index;
		i++;
		temp_a = temp_a->next;
	}
	return (sum / i);
}
