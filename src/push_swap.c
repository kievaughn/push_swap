#include "push_swap.h"

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

static long parse_long(const char **str)
{
    long result = 0;
    int is_negative = 0;

    if (**str == '+' || **str == '-')
        is_negative = (*((*str)++) == '-');
    if (**str < '0' || **str > '9')
        return LONG_MAX;
    while (**str >= '0' && **str <= '9')
    {
        int digit = **str - '0';

        if (result > (LONG_MAX - digit) / 10)
            return LONG_MAX;

        result = result * 10 + digit;
        (*str)++;
    }
    if (is_negative)
        return -result;
    else
        return result;
}

void	build_and_validate(int argc, char **argv, t_list **a)
{
    int         i;
    const char *ptr;
    long        value;
    t_list     *scan;
    t_list      *node;

    i = 1;
    while (i < argc)
    {
        ptr = argv[i++];
        while (*ptr)
        {
            while (*ptr == ' ' || *ptr == '\t')
                ptr++;
            if (!*ptr)
                break;
            value = parse_long(&ptr);
            if (value == LONG_MAX || value < INT_MIN || value > INT_MAX)
                error_exit_and_free(a);
            scan = *a;
            while (scan)
            {
                if (scan->content == (int)value)
                    error_exit_and_free(a);
                scan = scan->next;
            }
            node = ft_lstnew((int)value);
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
