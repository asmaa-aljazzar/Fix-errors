/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:49:27 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:29 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_target_a(t_stack_node *a, t_stack_node *b);
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b);

/**************************************************************/
//
//__ Combines all the functions needed to prepare [ a ], 
//    make it ready for pushing and sorting. 
//
//__ These functions set the data inside the node's structure
//
/**************************************************************/
void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}

/**************************************************************/
//
// med => store the med of the stack.---> len / 2
// index => for each node.
//
// When index < med this is mean it is above it.
//
/**************************************************************/
void	current_index(t_stack_node *stack)
{
	int	index;
	int	med;

	index = 0;
	if (!stack)
		return ;
	med = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = index;
		if (index <= med)
			stack->above_med = true;
		else
			stack->above_med = false;
		stack = stack->next;
		++index;
	}
}

/**************************************************************/
//
//*?	For each node a->nbr in stack a:
//
//*?		- It scans all nodes in [ b ] (current_b).
//*?		- It looks for a node in [ b ] that is smaller than [ a->num ].
//*?		- If multiple smaller numbers exist, it chooses the largest one 
//*?		  (the closest smaller number).
//*?		- If no smaller number exists:
//*?			- It chooses the largest number in [ b ] ==> find_max(b).
//
// current_b ==> pointer to the current node in [ b ] 
// and iterate through each node following.
//
// best_match_index ==> closest smaller number
// 
// Loop over [ a ], and Loop over [ b ] for each [ a ] node.
// 
// The new best match will be the number that < current and > last best match. 
//
// If best match not found then it will be max num
//
/**************************************************************/
static void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->num < a->num
				&& current_b->num > best_match_index)
			{
				best_match_index = current_b->num;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target = find_max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

/**************************************************************/
//
//__ Here we must choose [ ra or rra ] as example 
//   by determine if [ a ] and [ target ] above or bellow the med.
//
//*?	The cost for above med is [ index ].
//*?	The cost for bellow med is [ len - index ].
//
// Do this for all nodes in [ a ].
//
/**************************************************************/
static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_med))
			a->push_cost = len_a - (a->index);
		if (a->target->above_med)
			a->push_cost += a->target->index;
		else
			a->push_cost += len_b - (a->target->index);
		a = a->next;
	}
}

/**************************************************************/
//
// Set the [ cheapest ] attribute in all nodes as [ true ] or [ false ].
// use LONG_MAX to ensure that any number will be smaller than it.
//
// All cheapest is false as defult.
//
// If push cost < cheapest value it will be the new cheapest value 
// and the node will be the cheapest node. and then mark it as [ true ].
//
/**************************************************************/
void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		current->cheapest = false;
		current = current->next;
	}
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
