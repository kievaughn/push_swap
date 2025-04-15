#include "push_swap.h"

short int    is_sorted(t_list *lst)
{
    while (lst->next != NULL)
    {
        if (lst->content < lst->next->content)
            lst = lst->next;
        else
            return (0);
    }
    return (1);
}

void    small_sort(t_list **a)
{
    if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
    {
        swap(a);
        rotate_a(a);
    }
    if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content)
        swap(a);
    if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
        rotate_a(a);
    if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content
                    && (*a)->content > (*a)->next->next->content)
        reverse_rotate_a(a);
    if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
    {
        swap(a);
        reverse_rotate_a(a);
    }
}

void    move_to_b(t_list **a, t_list **b)
{
    int     median;
    int     i;

    i = 0;
    median = find_average(*a);
    while (i < (ft_lstsize(a)/2))
    {
        if ((*a)->index <= median)
        {
            push(a, b);
            i++;
        }
        else
            rotate_a(a);
    }
    while (ft_lstsize(a) > 3)
    {
        push(a, b);
    }
    small_sort(a);
}