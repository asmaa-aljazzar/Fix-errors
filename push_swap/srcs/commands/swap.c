/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:48:59 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:01 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack_node **head);
void		sa(t_stack_node **a, bool print);
void		sb(t_stack_node **b, bool print);
void		ss(t_stack_node **a, t_stack_node **b, bool print);

//__ The print argument is because to determine if output operation 
//   or not because in ss we not print [ sa , sb ]...etc
void	sa(t_stack_node **a, bool print)
{
	swap (a);
	if (print)
		ft_printf ("sa\n");
}

void	sb(t_stack_node **b, bool print)
{
	swap (b);
	if (print)
		ft_printf ("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap (a);
	swap (b);
	if (print)
		ft_printf ("ss\n");
}

// The header will be the second node.
//
// The prev of the old [ first ]  will be the new one.
// The next of the old [ first ] is the next of the old [ second ].
// 
// If there is a node next to the old [ seconde ],
// then make its prev point to the old [ first ].
//
// the next of the new first is the prev of it.
// the prev of the new first is NULL.
static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}
