#include "push_swap.h"

int error_syntax(char *s)
{
    if (!(*s == '+' || *s == '-'
            || (*s >= '0' && *s <= '9')))
        return (1);
    if ((*s == '+' || *s == '-')
            && !(s[1] >= '0' && s[1] <= '9'))
        return (1);
    while (*++s)
    {
        if (!(*s >= '0' && *s <= '9'))
            return (1);
    }
    return (0);
}

int error_duplicate(t_stack *a, int n)
{
    if (!a)
        return (0);
    while (a)
    {
        if (a->nbr == n)
            return (1);
        a = a->next;
    }
    return (0);
}

void    free_stack(t_stack **stack)
{
    t_stack *tmp;
    t_stack *current;

    if (!stack)
        return ;
    current = *stack;
    while (current)
    {
        tmp = current->next;
        current->nbr = 0;
        free(current);
        current = tmp;
    }
    *stack = NULL; 
}

void    free_errors(t_stack **a)
{
    free_stack(a);
    ft_printf("ERROR\n");
    exit(1);
}