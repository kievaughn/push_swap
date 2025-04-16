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
        swap(a, 'a');
        rotate(a, 'a');
    }
    if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content)
        swap(a, 'a');
    if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
        rotate(a, 'a');
    if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content
                    && (*a)->content > (*a)->next->next->content)
        reverse_rotate(a, 'a');
    if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
    {
        swap(a, 'a');
        reverse_rotate(a, 'a');
    }
}

void    move_to_b(t_list **a, t_list **b)
{
    int     median;
    int     i;

    i = 0;
    median = find_median(*a);
    while (i < (ft_lstsize(*a)/2))
    {
        if ((*a)->index <= median)
        {
            push(a, b, 'b');
            i++;
        }
        else
            rotate(a, 'a');
    }
    while (ft_lstsize(*a) > 3)
    {
        push(a, b, 'b');
    }
    small_sort(a);
}


void    move_to_a(t_list **a, t_list **b)
{
    t_list  *cheapest;
    t_list  *temp_a;

    while(ft_lstsize(*b) != 0)
    {
        set_cost(*a, *b);
        cheapest = get_cheapest(*a, *b);
        temp_a = *a;
        while (cheapest && cheapest->cost_to_top > 0)
        {
            rotate(b, 'b');
            cheapest->cost_to_top--;
        }
        while (temp_a)
        {
            if (cheapest && cheapest->nearest == temp_a->index)
            {
                while (temp_a->cost_to_top > 0)
                {
                    rotate(a, 'a');
                    temp_a->cost_to_top--;
                }
            }
            temp_a = temp_a->next;
        }
        push(b, a, 'a');
    }
}

void    last_rotate(t_list **a)
{
    while((*a)->index != 1)
        rotate(a, 'a');
}
