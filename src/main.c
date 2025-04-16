#include "push_swap.h"

#include <stdio.h>

void	print_list(t_list *lst, char lstname)
{
	printf("(%d)%c -> ", ft_lstsize(lst), lstname);
	while (lst != NULL)
	{
		printf("%d ", lst->index);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
    int     i;

    i = 1;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		while(argv[i] != NULL)
		{
			ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
			i++;
		}
	}

	if(argc == 4)
	{
		small_sort(&a);
		set_cost(a, b);
	}
	else
	{
		set_index(a);
		move_to_b(&a, &b);
		set_cost(a, b);
		move_to_a(&a, &b);
	}
	last_rotate(&a);
    //print_list(a, 'a');
	//free_all(&a, &b);
	return (0);
}