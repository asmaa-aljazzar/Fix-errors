/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:49:15 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:16 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_errors(t_stack_node **a);
void	free_stack(t_stack_node **a);
int		error_duplicate(t_stack_node *a, int num);
int		error_syntax(char *argv);

// return [ 1 ] if one of the following exist.
// return [ 0 ] if no one of the following exist.
//
// if the first char not a number or not a [ + , - ] sign.
// if the first char is a sign but the next one is not a number.
// if the rest of the string contain any char that is not a number.
int	error_syntax(char *argv)
{
	if (!(*argv == '+'
			|| *argv == '-'
			|| (*argv >= '0' && *argv <= '9')))
		return (1);
	if ((*argv == '+'
			|| *argv == '-')
		&& !(argv[1] >= '0' && argv[1] <= '9'))
		return (1);
	while (*++argv)
		if (!(*argv >= '0' && *argv <= '9'))
			return (1);
	return (0);
}

// return [ 1 ] when there is a duplicate.
// return [ 0 ] when no duplicate found.
int	error_duplicate(t_stack_node *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->num == num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_errors(t_stack_node **a)
{
	free_stack (a);
	write(2, "Error\n", 6);
	exit(1);
}

//__ Temp node to store the next node before free the current one.
void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->num = 0;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}
