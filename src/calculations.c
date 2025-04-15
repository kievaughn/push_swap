#include "push_swap.h"

void    set_index(t_list *lst)
{
    int		index;
	t_list	*temp;
	t_list	*temp_node;
	int		size;

	index = 1;
	size = ft_lstsize(lst);
	while (index <= size)
	{
		temp = lst;
		temp_node = NULL;
		while(temp)
		{
			if (temp->index == 0 && (temp_node == NULL || temp->content < temp_node->content))
				temp_node = temp;
			temp = temp->next;
		}
		if (temp_node != NULL)
		{
			temp_node->index = index;
			index++;
		}
	}
}

int     find_median(t_list *a)
{
    int     sum;
    int     i;

    sum = 0;
    i = 0;
    while(a)
    {
        sum += a->index;
		i++;
        a = a->next;
    }
    return(sum/i);
}