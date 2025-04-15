#include "push_swap.h"

#include <stdio.h>

void	print_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d ", lst->content);
		printf("%d \n", lst->index);
		lst = lst->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*a;
    int     i;

    i = 1;
	a = NULL;
	if (argc < 2)
		return (0);
    while(argv[i] != NULL)
    {
        ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
        i++;
    }
	set_index(a);
	small_sort(&a);
	printf("%d \n", find_average(a));
    //print_list(a);
	//printf("%d\n", is_sorted(a));
	//free_all(&a, &b);
	return (0);
}