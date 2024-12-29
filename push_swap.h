/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:41:18 by rhiguita          #+#    #+#             */
/*   Updated: 2024/12/06 15:25:37 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct  s_stack
{
    int     nbr;
    int     index;
    int     push_cost;
    bool    above_median;
    bool    cheapest;
    struct s_stack *target_node;
    struct s_stack *next;
    struct s_stack *prev;
}   t_stack;

//int	main(int argc, char **argv);


//ERRORS
int     error_syntax(char *s);
int     error_duplicate(t_stack *a, int n);
void    free_stack(t_stack **stack);
void    free_errors(t_stack **a);

// STACK INITIATION
void	init_stack_a(t_stack **a, char **argv);

//NODES INITIATION
void    init_nodes_a(t_stack *a, t_stack *b);
void    init_nodes_b(t_stack *a, t_stack *b);
void	current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);
void    prep_for_push(t_stack **s, t_stack *n, char c);

//STACK UTILS
int stack_len(t_stack *stack);
t_stack *find_last(t_stack *stack);
bool    stack_sorted(t_stack *stack);
t_stack *find_min(t_stack *stack);
t_stack *find_max(t_stack *stack);

// COMMANDS
void    sa(t_stack **a, bool print);
void    sb(t_stack **b, bool print);
void    ss(t_stack **a, t_stack **b, bool print);
void    ra(t_stack **a, bool print);
void    rb(t_stack **b, bool print);
void    rr(t_stack **a, t_stack **b, bool print);
void    rra(t_stack **a,  bool print);
void    rrb(t_stack **b, bool print);
void    rrr(t_stack **a, t_stack **b, bool print);
void    pa(t_stack **a, t_stack **b, bool print);
void    pb(t_stack **b, t_stack **a, bool print);

// ALGORITHM
void    sort_three(t_stack **a);
void    sort_stacks(t_stack **a, t_stack **b);

#endif
