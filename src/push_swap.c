/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:39:10 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/05 17:40:39 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit_and_free(t_list **a)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	write(2, "Error\n", 6);
	exit(1);
}

static long	parse_long(const char **str)
{
	long	result;
	int		is_negative;
	int		digit;

	result = 0;
	is_negative = 0;
	if (**str == '+' || **str == '-')
		is_negative = (*((*str)++) == '-');
	if (**str < '0' || **str > '9')
		return (LONG_MAX);
	while (**str >= '0' && **str <= '9')
	{
		digit = **str - '0';
		if (result > (LONG_MAX - digit) / 10)
			return (LONG_MAX);
		result = result * 10 + digit;
		(*str)++;
	}
	if (is_negative)
		return (-result);
	else
		return (result);
}

static void	validate_and_add(const char **p, t_list **a)
{
	long	value;
	t_list	*scan;
	t_list	*node;

	value = parse_long(p);
	if (value == LONG_MAX || value < INT_MIN || value > INT_MAX)
		error_exit_and_free(a);
	scan = *a;
	while (scan)
	{
		if (scan->content == (int)value)
			error_exit_and_free(a);
		scan = scan->next;
	}
	node = ft_lstnew((int)value);
	if (!node)
		exit(1);
	ft_lstadd_back(a, node);
}

void	build_and_validate(int argc, char **argv, t_list **a)
{
	int			i;
	const char	*ptr;

	i = 1;
	while (i < argc)
	{
		ptr = argv[i++];
		while (*ptr)
		{
			while (*ptr == ' ' || *ptr == '\t')
				ptr++;
			if (!*ptr)
				break ;
			validate_and_add(&ptr, a);
		}
	}
}

void	push_swap(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 1)
		return ;
	if (is_sorted(*a))
		return ;
	if (size == 2)
	{
		set_index(*a);
		last_rotate(a);
		return ;
	}
	if (size == 3)
	{
		small_sort(a);
		return ;
	}
	set_index(*a);
	move_to_b(a, b);
	set_cost(*a);
	set_cost(*b);
	move_to_a(a, b);
	last_rotate(a);
}
