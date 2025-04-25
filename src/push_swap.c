#include "push_swap.h"

// void build_stack(char **argv, t_list **a)
// {
// 	int i = 1;

// 	while (argv[i])
// 	{
// 		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
// 		i++;
// 	}
// }

// void push_swap(int argc, t_list **a, t_list **b)
// {
// 	if (argc == 4)
// 		small_sort(a);
// 	else
// 	{
// 		set_index(*a);
//         if (argc > 3)
//         {
//             move_to_b(a, b);
//             set_cost(*a);
//             set_cost(*b);
//             move_to_a(a, b);
//         }
//         last_rotate(a);
// 	}	
// }

static void		error_exit_and_free(t_list **a)
{
    t_list *tmp;
    while (*a)
    {
        tmp = (*a)->next;
        free(*a);
        *a = tmp;
    }
    write(2, "Error\n", 6);
    exit(1);
}

static long		parse_long(const char **s)
{
    long acc = 0;
    int  neg = 0;

    /* optional '+' / '-' */
    if (**s == '+' || **s == '-')
        neg = (*((*s)++) == '-');

    /* must see at least one digit */
    if (**s < '0' || **s > '9')
        return LONG_MAX;

    /* accumulate, with overflow check */
    while (**s >= '0' && **s <= '9')
    {
        int d = **s - '0';
        if (acc > (LONG_MAX - d) / 10)
            return LONG_MAX;
        acc = acc * 10 + d;
        (*s)++;
    }
    return neg ? -acc : acc;
}

void	build_and_validate(int argc, char **argv, t_list **a)
{
    int         i = 1;
    const char *p;
    long        v;
    t_list     *scan, *node;

    while (i < argc)
    {
        p = argv[i++];
        while (*p)
        {
            while (*p == ' ' || *p == '\t')
                p++;
            if (!*p)
                break;
            v = parse_long(&p);
            if (v == LONG_MAX || v < INT_MIN || v > INT_MAX)
                error_exit_and_free(a);
            scan = *a;
            while (scan)
            {
                if (scan->content == (int)v)
                    error_exit_and_free(a);
                scan = scan->next;
            }
            node = ft_lstnew((int)v);
            if (!node)
                exit(1);
            ft_lstadd_back(a, node);
        }
    }
}

void	push_swap(t_list **a, t_list **b)
{
    int size;
	
	size = ft_lstsize(*a);
    if (size <= 1)
        return;
    if (size == 2)
    {
        set_index(*a);
        last_rotate(a);
        return;
    }
    if (size == 3)
    {
        small_sort(a);
        return;
    }
    set_index(*a);
    move_to_b(a, b);
    set_cost(*a);
    set_cost(*b);
    move_to_a(a, b);
    last_rotate(a);
    
}
