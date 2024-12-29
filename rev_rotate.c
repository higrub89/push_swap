#include "push_swap.h"

static void rev_rotate(t_stack **stack)
{
    t_stack *last;
    
    if (!*stack || !(*stack)->next)
        return ;
    last = find_last(*stack);
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    *stack = last;
    last->next->prev  = last;
}

void    rra(t_stack **a,  bool print)
{
    rev_rotate(a);
    if (!print)
        ft_printf("rra\n");
}

void    rrb(t_stack **b, bool print)
{
    rev_rotate(b);
    if (!print)
        ft_printf("rrb\n");
}

void    rrr(t_stack **a, t_stack **b, bool print)
{
    rev_rotate(a);
    rev_rotate(b);
    if (!print)
        ft_printf("rrr\n");    
}