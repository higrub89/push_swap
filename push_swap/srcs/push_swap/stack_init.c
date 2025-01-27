/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:41:14 by rhiguita          #+#    #+#             */
/*   Updated: 2025/01/27 20:45:18 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *s)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r' || *s == '\f'
		|| *s == '\v')
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

static void	handle_argument(t_stack_node **a, char *arg)
{
	long	n;

	arg = remove_spaces(arg);
	if (error_syntax(arg))
		free_errors(a);
	n = ft_atol(arg);
	if (n > INT_MAX || n < INT_MIN)
		free_errors(a);
	if (error_duplicate(*a, (int)n))
		free_errors(a);
	append_node(a, (int)n);
}

static void	process_arguments(t_stack_node **a, char **args)
{
	int		j;
	char	*arg;

	j = 0;
	while (args[j])
	{
		arg = args[j];
		handle_argument(a, arg);
		j++;
	}
}

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	while (argv[i])
	{
		args = split_push_swap(argv[i], ' ');
		process_arguments(a, args);
		i++;
	}
}
