/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:57:57 by rhiguita          #+#    #+#             */
/*   Updated: 2025/01/05 12:58:00 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s) 
{
	long	result;
	int		sign;

	result = 0;
	sign = 1; 
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\r' || *s == '\f' || *s == '\v')
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');
	return (result * sign);
}

static void	append_node(t_stack_node **stack, int n) 
{
	t_stack_node	*node; 
	t_stack_node	*last_node; 

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node)); 
	if (!node)
		return ;
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
		last_node->next = node; 
		node->prev = last_node; 
	}
}

void	init_stack_a(t_stack_node **a, char **argv) 
{
	long	n;
	int		i;
	int		j;
	char	**args;
	char	*arg;

	i = 0;
	while (argv[i])
	{
		args = split_push_swap(argv[i], ' ');
		j = 0;
		while (args[j])
		{
			arg = remove_spaces(args[j]);
			if (error_syntax(arg))
				free_errors(a);
			n = ft_atol(arg);
			if (n > INT_MAX || n < INT_MIN) 
				free_errors(a);
			if (error_duplicate(*a, (int)n))
				free_errors(a); 
			append_node(a, (int)n);
			j++;
		}
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack) 
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

void	prep_for_push(t_stack_node **stack,
						t_stack_node *top_node,
						char stack_name) 
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