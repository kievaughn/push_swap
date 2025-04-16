/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:23:33 by kbrandon          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:30 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puthex(unsigned long int n)
{
	char	*hex_digits;
	char	hex_str[17];
	int		i;
	int		count;

	i = 15;
	count = 0;
	hex_digits = "0123456789abcdef";
	if (n == 0 && write(1, "0", 1) > 0)
		return (1);
	else if (n == 0 && write(1, "0", 1) < 0)
		return (-1);
	while (n > 0)
	{
		hex_str[i] = hex_digits[n % 16];
		n = n / 16;
		i--;
	}
	count = write(1, &hex_str[i + 1], 15 - i);
	if (count < 0)
		return (-1);
	else
		return (count);
}

int	ft_puthexcaps(unsigned long int n)
{
	char	*hex_digits;
	char	hex_str[17];
	int		i;
	int		count;

	i = 15;
	count = 0;
	hex_digits = "0123456789ABCDEF";
	if (n == 0 && write(1, "0", 1) > 0)
		return (1);
	else if (n == 0 && write(1, "0", 1) < 0)
		return (-1);
	while (n > 0)
	{
		hex_str[i] = hex_digits[n % 16];
		n = n / 16;
		i--;
	}
	count = write(1, &hex_str[i + 1], 15 - i);
	if (count < 0)
		return (-1);
	else
		return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	hex_count;

	count = 0;
	hex_count = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count < 0)
		return (-1);
	hex_count = ft_puthex((unsigned long)ptr);
	if (hex_count < 0)
		return (-1);
	return (count + hex_count);
}
