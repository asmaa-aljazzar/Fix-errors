/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:23:54 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:24:00 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libraries
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <stdbool.h>
# include <limits.h>
	// stdbool ---> to printing list of commands.
	// limits  ---> int Min & int Max.

// List Structure
// index --> number's position in the stack.
// push_cost --> number of commands in total.
// target --> node in the other stack.
//
typedef struct s_stack_node
{
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
	struct s_stack_node	*target;
	bool				above_med;
	bool				cheapest;
	int					num;
	int					index;
	int					push_cost;
}	t_stack_node;

//*****[ Functions Definetion ]*****
t_stack_node	*get_cheapest(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
int				error_duplicate(t_stack_node *a, int num);
int				error_syntax(char *argv);
int				stack_len(t_stack_node *stack);
bool			issorted_stack(t_stack_node *stack);
void			free_errors(t_stack_node **a);
void			free_stack(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			sort_three(t_stack_node **a);
void			sorting(t_stack_node **a, t_stack_node **b);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);
#endif
