/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:50 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:48:54 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//__ To sort the stack contain three numbers.
//__ Find biggest node.
//
//__ If the [ first ] is the biggest_node
//*!      |--> ra
//   if the  [ second ] is maximum set it as biggest node 
//*!      |--> rra: go to the bottom 
//   Then swap first 2 numbers
//*!        |--> sa
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->num > (*a)->next->num)
		sa(a, true);
}
