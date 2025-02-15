/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:08 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:48:10 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src);
void		pa(t_stack_node **a, t_stack_node **b, bool print);
void		pb(t_stack_node **a, t_stack_node **b, bool print);

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (print)
		ft_printf("pb\n");
}

//__ Check if src exist.
//
//__ The push node  = header of [ src ].
//
//__ The first element is the second one in the src.
//*!     | but must check if there is a second element to give it a prev value.
//
//__ The prev of the push node is NULL ==> on the top of [ dst ].
//
//__ If no element in the dst the node will be the first one
//   if not the next of it is the first element, and it will be the prev of it .
//
//__ giv the [ dst ] pointer to the node.

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}
