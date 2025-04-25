#include "push_swap.h"

#include <stdio.h>

void	print_list(t_list *lst, char lstname)
{
	printf("(%d)%c -> ", ft_lstsize(lst), lstname);
	while (lst != NULL)
	{
		printf("i: %d ", lst->index);
		printf("n: %d //", lst->nearest);
		lst = lst->next;
	}
	printf("\n");
}

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
	}
	return (0);
}
