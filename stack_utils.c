#include "push_swap.h"

int stack_len(t_stack *stack)
{
    int i;

    if (!stack)
        return (0);
    i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

t_stack *find_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

bool    stack_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->nbr > stack->next->nbr)
            return (false);
        stack = stack->next;
    }
    return (true);
}

t_stack *find_min(t_stack *stack)
{
    long    min;
    t_stack *min_node;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while (stack)
    {
        if (stack->nbr < min)
        {
            min = stack->nbr;
            min_node = stack;
        }
        stack = stack->next;
    }
    return (min_node);
}

t_stack *find_max(t_stack *stack)
{
    long    max;
    t_stack *max_node;

    if (!stack)
        return (NULL);
    max = LONG_MIN;
    while (stack)
    {
        if (stack->nbr  > max)
        {
            max = stack->nbr;
            max_node = stack;
        }
        stack = stack->next;
    }
    return (max_node);
}