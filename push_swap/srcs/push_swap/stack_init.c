/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:50:11 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:50:14 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static long	ft_tolong(char *str);
static void	append_to_stack(t_stack_node **stack, int n);

// Create the [ a ] stack and handle error.
//
// The nodes is appending to the stack one by one.
//
// Casting to int is safe because of check INT_MAX, INT_MIN
void	init_stack_a(t_stack_node **a, char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a);
		num = ft_tolong(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)num))
			free_errors(a);
		append_to_stack(a, (int)num);
		i++;
	}
}

// Converts string into a long value
static long	ft_tolong(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || \
			*str == '\r' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

// Cheapest: 
// 	node->cheapest = 0, to avoid valgrind issues.
static void	append_to_stack(t_stack_node **stack, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->num = n;
	node->cheapest = 0;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// moves the required node to the top of the stack
// by determine if it is [ b ] or [ a ] and above or bellow the [ med ].
void	prep_for_push(t_stack_node **stack,
		t_stack_node *top_node,
		char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_med)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_med)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}
