/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:03 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:48:05 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/********************************************************* */
//
// Here we will check if the node and tha target both 
// is above or bellow the med so we can rotate or rotate_rev both.
//
// but if one of them is above and the other one is bellow we will
// [ a ] node at the top.
//
// It will continue rotate / rotate_rev until the [ a ] and target
// are the first nodes, and then last check with prepare for push.
/********************************************************* */
void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_med
		&& cheapest_node->target->above_med)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_med)
		&& !(cheapest_node->target->above_med))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a, true);
}

// The loop will continue while the first element not the cheapest one.
// After change the order, Reset the indexes.
void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rr(a, b, true);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b, true);
	current_index(*a);
	current_index(*b);
}

// push back b to a
void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, true);
}

// moves the smallest number to the top in final [ a ].
// While first element is not the minimum
// do ra or rra until it is
void	min_on_top(t_stack_node **a)
{
	while ((*a)->num != find_min(*a)->num)
	{
		if (find_min(*a)->above_med)
			ra(a, true);
		else
			rra(a, true);
	}
}
