/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:13:30 by kbrandon          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:30 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	storenum(int *i, char *str, int *n)
{
	while (*n > 0)
	{
		str[*i] = (*n % 10) + '0';
		*n = *n / 10;
		(*i)++;
	}
	(*i)--;
}

static int	zero_min(int count, int n)
{
	if (n == 0)
	{
		count = write(1, "0", 1);
		if (count < 0)
			return (-1);
		return (count);
	}
	else if (n == -2147483648)
	{
		count = write(1, "-2147483648", 11);
		if (count < 0)
			return (-1);
		return (count);
	}
	return (-1);
}

static int	printneg(int *count, int *n)
{
	*count = write(1, "-", 1);
	if (*count < 0)
		return (-1);
	*n *= -1;
	return (0);
}

int	ft_putnbr(int n)
{
	char	str[11];
	int		i;
	int		count;
	int		result;

	i = 0;
	count = 0;
	result = 0;
	if (n == 0 || n == -2147483648)
		return (zero_min(count, n));
	if (n < 0 && n != -2147483648)
	{
		if (printneg(&count, &n) < 0)
			return (-1);
	}
	storenum(&i, str, &n);
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
