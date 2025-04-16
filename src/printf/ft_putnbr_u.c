/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:10 by kbrandon          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:30 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	storenum_u(int *i, char *str, unsigned int *n)
{
	while (*n > 0)
	{
		str[*i] = (*n % 10) + '0';
		*n = *n / 10;
		(*i)++;
	}
}

static int	zero(int count, long int n)
{
	if (n == 0)
	{
		count = write(1, "0", 1);
		if (count < 0)
			return (-1);
		return (count);
	}
	return (0);
}

int	ft_putnbr_u(unsigned int n)
{
	char	str[11];
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	result = 0;
	if (n == 0)
		return (zero(count, n));
	storenum_u(&i, str, &n);
	i--;
	while (i >= 0)
	{
		result = write(1, &str[i], 1);
		if (result < 0)
			return (-1);
		count += result;
		i--;
	}
	return (count);
}
