/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:01:47 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/06 15:16:02 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	deleted_content(void *content)
{
	free(content);
}

void    print_list(t_list *l)
{
	int	i;

	i = 0;
        while(l  != NULL)
        {
                printf("nodo[%i] =  %s\n", i, (char *)(l->content));
                l = l->next;
		i++;
        }
}

int	main(int argc, char **argv)
{
	int	i;
	t_list *n;

	n = NULL;
	i = 1;
	while(argc > i)
	{
		ft_lstadd_back(&n, ft_lstnew(ft_strdup(argv[i++])));
	}
	print_list(n);
	ft_lstclear(&n, deleted_content);
	return (0);
}*/

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0); ///////////
}