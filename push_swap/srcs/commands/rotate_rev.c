/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:31 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:52:12 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate_rev(t_stack_node **stack);
void		rra(t_stack_node **a, bool print);
void		rrb(t_stack_node **b, bool print);
void		rrr(t_stack_node **a, t_stack_node **b, bool print);

void	rra(t_stack_node **a, bool print)
{
	rotate_rev(a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rotate_rev(b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate_rev(a);
	rotate_rev(b);
	if (print)
		ft_printf("rrr\n");
}

//__ The last node will be the first.
//
//__ the next of the [ new ] last will be NULL.
//__ the next of the [ old ] last will be the [ old ] first.
//__ the prev of the [ old ] last will be NULL.
//__ the poiner of the stack will be the [ new ] first.
//__ the prev of the [ old ] first will be the [ new ] first.
static void	rotate_rev(t_stack_node **stack)
{
	t_stack_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
