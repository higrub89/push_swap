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

void	free_stack(t_stack **stack) //Define a function to free a stack if there are errors
{
	t_stack	*tmp; //To store the next node in the stack before the current node is freed, because once a node is freed, you can't access its next pointer
	t_stack	*current;

	if (!stack) //Check for an empty stack
		return ;
	current = *stack;
	while (current) //As long as a node exist in the stack
	{
		tmp = current->next; //Assign to `tmp` the pointer to the next node
		current->nbr = 0; //Assigning the node to `0` before freeing is not strictly necessary but it can help catch potential bugs such as memory-leaks and improve debugging
		free(current); //Free the current node, deallocating the memory occupied by that node
		current = tmp; //Assign `tmp` as the current first node
	}
	*stack = NULL;
}

void    free_errors(t_stack **a)
{
    printf("Liberando nodo");
    free_stack(a);
    ft_printf("ERROR\n");
    exit(1);
}