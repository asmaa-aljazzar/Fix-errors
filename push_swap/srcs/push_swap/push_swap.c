/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaljazza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:49:43 by aaljazza          #+#    #+#             */
/*   Updated: 2025/02/15 11:49:45 by aaljazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// argv + 1 : like make it argv1 argv2 ....etc
// If 2 args ==> "num1 num2 num3" ==> split();
// init stack
//
//__ If not sorted choose an algorithm by number of numbers.
int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack_a(&a, argv + 1);
	if (!issorted_stack(a))
	{
		if (stack_len(a) == 2)
			sa(&a, true);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sorting(&a, &b);
	}
	free_stack(&a);
	return (0);
}
