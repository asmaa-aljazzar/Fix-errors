/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:39 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:48:41 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sorting(t_stack_node **a, t_stack_node **b);

/********************************************************* */
//
// Sorting more than three numbers.
//
//__ Calculate the length of [ a ].
//      | if len > 3 push 2 number to [ b ].
//
//__ If still len > 3   
//      | continue push to [ b ] while sorting desending 
//        (put it in the right place).
//      | but must initialize th node
//
//__ Initiate all nodes in both stacks
//__ Move the cheapest [ a ] nodes into [ b ], the node will be sorted,
//*!    | Do this two steps until there is 3 nodes in [ a ].
//
//__ Sort the three nodes.
//
//__ Reinitiate all nodes in both stack.
//__ Move back from [ b ] to [ a ] until the end of [ b ].
//
//__ Refresh the current position of [ a ].
//
//__ min_on_top will ensure that smallest number is on top.
//
/********************************************************* */
void	sorting(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !issorted_stack(*a))
		pb(b, a, true);
	if (len_a-- > 3 && !issorted_stack(*a))
		pb(b, a, true);
	while (len_a-- > 3 && !issorted_stack(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
