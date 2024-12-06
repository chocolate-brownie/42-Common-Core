/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:35:03 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 10:37:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(const int argc, char *argv[])
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	init_stack(&stack_a, &stack_b);
	control_arguments(argc, argv, &stack_a);
}

int	control_arguments(const int argc, char **argv, t_stack_node **a)
{
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	argv += 1;
	return (0);
}

void	init_stack(t_stack_node **a, t_stack_node **b)
{
	*a = NULL;
	*b = NULL;
}
