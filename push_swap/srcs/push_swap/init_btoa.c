/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:49:36 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:38 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b);
void		init_nodes_b(t_stack_node *a, t_stack_node *b);

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}

// Same with set target [ a ] but in opposite.
// 
// use LONG_MAX. to compare.
//
// use FIND_MIN if no best match
//
// Check if the [ a ] node's value is bigger
//
// than [ b ] node, && smaller than the "closest bigger".
static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->num > b->num
				&& current_a->num < best_match_index)
			{
				best_match_index = current_a->num;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}
