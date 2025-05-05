/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:39:04 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/05 17:39:05 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_list *lst)
{
	int		index;
	t_list	*temp;
	t_list	*temp_node;
	int		size;

	index = 1;
	size = ft_lstsize(lst);
	while (index <= size)
	{
		temp = lst;
		temp_node = NULL;
		while (temp)
		{
			if (temp->index == 0 && (temp_node == NULL
					|| temp->content < temp_node->content))
				temp_node = temp;
			temp = temp->next;
		}
		if (temp_node != NULL)
		{
			temp_node->index = index;
			index++;
		}
	}
}

void	set_cost(t_list *lst)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(lst);
	while (lst)
	{
		if (i > size / 2)
		{
			lst->cost_to_top = size - i;
			lst->reverse = 1;
		}
		else
		{
			lst->cost_to_top = i;
			lst->reverse = 0;
		}
		i++;
		lst = lst->next;
	}
}

void	set_lowest(t_list *a, t_list *b)
{
	int		lowest;
	t_list	*temp_a;
	t_list	*temp_b;

	lowest = INT_MAX;
	temp_a = a;
	temp_b = b;
	while (temp_a)
	{
		if (temp_a->index < lowest)
			lowest = temp_a->index;
		temp_a = temp_a->next;
	}
	while (temp_b)
	{
		if (temp_b->nearest == 0)
			temp_b->nearest = lowest;
		temp_b = temp_b->next;
	}
}

void	set_nearest(t_list *a, t_list *b)
{
	t_list	*temp_b;

	temp_b = b;
	while (temp_b)
	{
		temp_b->nearest = 0;
		temp_b = temp_b->next;
	}
	temp_b = b;
	while (temp_b)
	{
		set_nearest_higher(a, temp_b);
		temp_b = temp_b->next;
	}
	set_lowest(a, b);
}

t_list	*get_cheapest(t_list *a, t_list *b)
{
	t_list	*cheapest_node;
	int		cheapest;
	int		total_cost;

	cheapest_node = NULL;
	cheapest = INT_MAX;
	set_nearest(a, b);
	while (b)
	{
		total_cost = get_total_cost(a, b);
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	return (cheapest_node);
}
