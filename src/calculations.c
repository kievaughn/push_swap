#include "push_swap.h"

void    set_index(t_list *lst)
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
		while(temp)
		{
			if (temp->index == 0 && (temp_node == NULL || temp->content < temp_node->content))
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

void	set_cost(t_list *a, t_list *b)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = a;
	temp_b = b;
	i = 0;
	while(temp_a)
	{
		temp_a->cost_to_top = i;
		i++;
		temp_a = temp_a->next;
	}
	i = 0;
	while(temp_b)
	{
		temp_b->cost_to_top = i;
		i++;
		temp_b = temp_b->next;
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
	t_list	*temp_a;
	t_list	*temp_b;
	int		nearest;

	temp_b = b;
	while (temp_b)
	{
		temp_b->nearest = 0;
		temp_b = temp_b->next;
	}
	temp_b = b;
	while(temp_b)
	{
		temp_a = a;
		nearest = INT_MAX;
		while(temp_a)
		{
			if ((temp_a->index - temp_b->index < nearest) && (temp_a->index - temp_b->index > 0))
			{
				temp_b->nearest = temp_a->index;
				nearest = temp_a->index - temp_b->index;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
	set_lowest(a, b);
}

t_list	*get_cheapest(t_list *a, t_list *b)
{
	t_list	*cheapest_node;
	int		cheapest;
	int 	total_cost;
	t_list *temp_a;

	cheapest_node = NULL;
	cheapest = INT_MAX;
	set_nearest(a, b);
	while (b)
	{
		total_cost = b->cost_to_top;
		temp_a = a;
		while (temp_a)
		{
			if (temp_a->index == b->nearest)
			{
				total_cost += temp_a->cost_to_top;
				break;
			}
			temp_a = temp_a->next;
		}
		if (total_cost < cheapest)
		{
			cheapest = total_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	return (cheapest_node);
}

int     find_median(t_list *a)
{
    int     sum;
    int     i;
	t_list *temp_a;

    sum = 0;
    i = 0;
	temp_a = a;
    while(temp_a)
    {
        sum += temp_a->index;
		i++;
        temp_a = temp_a->next;
    }
    return(sum/i);
}