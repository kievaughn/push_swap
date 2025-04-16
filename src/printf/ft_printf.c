/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:18:21 by kbrandon          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:30 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checkprint(va_list args, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		count = ft_putptr((va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		count = ft_putnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		count = ft_puthex(va_arg(args, unsigned int));
	else if (c == 'X')
		count = ft_puthexcaps(va_arg(args, unsigned int));
	else if (c == '%')
		count = ft_putchar('%');
	return (count);
}

static int	print_nonformat(char *s, int *result, int *count)
{
	*result = (write(1, s, 1));
	if (*result < 0)
		return (-1);
	*count += *result;
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			count;
	int			result;

	count = 0;
	result = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			result = checkprint(args, *s);
			if (result < 0)
				return (-1);
			count += result;
		}
		else
			print_nonformat((char *)s, &result, &count);
		s++;
	}
	va_end(args);
	return (count);
}
