#include "push_swap.h"

static long    push_atol(const char *s)
{
    long    result;
    int     sig;

    result = 0;
    sig = 1;
    while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sig = -1;
        s++;
    }
    while (ft_isdigit(*s))
        result = result * 10 + (*s++ - '0');
    return (result * sig);
}

static int append_node(t_stack **stack, int n)
{
    t_stack	*node;
    t_stack *last_node;

    if (!stack)
        return (-1);
    node = malloc(sizeof(t_stack));
    if (!node)
	{
		ft_printf("ERROR ASIGNACION MEMORIA\n");
		return (-1);
	}
    node->next = NULL;
    node->nbr = n;
    node->cheapest = 0;
    if (!(*stack))
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last(*stack);
		if (!last_node)
		{
			 ft_printf("ERROR: find_last devolvió NULL\n");
            free(node);
            return (-1);
		}
        last_node->next = node;
        node->prev = last_node;
    }
	return (0);
}

void	init_stack_a(t_stack **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
		{
			ft_printf("ERROR DE SINTAXIS en %s\n", argv[i]);
			free_errors(a);
			return ;
		}
		n = push_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			ft_printf("Numero fuera de rango %ld\n", n);
			free_errors(a);
			return ;
		}
		if (error_duplicate(*a, (int)n))
		{
			ft_printf("Numero duplicado %d\n", (int)n);
			free_errors(a);
			return ;
		}
		if (append_node(a, (int)n) != 0)
		{   ft_printf("ERROR al agregar nodo\n");
            free_errors(a);
            return;
		}
		i++;
	}
}

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}