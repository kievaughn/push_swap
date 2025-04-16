/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:13:32 by kbrandon          #+#    #+#             */
/*   Updated: 2025/04/16 18:22:30 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *s)
{
	int				count;
	int				result;

	count = 0;
	result = 0;
	if (!s)
		s = "(null)";
	while (*s)
	{
		result = write(1, s, 1);
		if (result < 0)
			return (-1);
		count += result;
		s++;
	}
	return (count);
}
