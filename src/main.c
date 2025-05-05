/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrandon <kbrandon@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:38:59 by kbrandon          #+#    #+#             */
/*   Updated: 2025/05/05 17:41:41 by kbrandon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		build_and_validate(argc, argv, &a);
		push_swap(&a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
		free(a);
		free(b);
	}
	return (0);
}
