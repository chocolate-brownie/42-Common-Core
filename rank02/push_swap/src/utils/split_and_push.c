/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/22 17:52:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the numbers are as "SINGLE STRING" argv[1] split the string
and push them into the stack_a

	-- Handle integer overflows, duplicates, and sytax errors, (input must only
	contains digits, '+' or '-' signs if errors found, free stack A and return
	error)
	-- Check for each input if it's a long integer, if it is convert it into
	a long integer

if everything is good append the numbers as nodes to the stack_a */
t_list	*split_and_push(char *str, t_list *stack)
{
	char **split = ft_split(str, stack);
	if (!split)
		error_exit();

	int i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]))
		{
			free_split(split);
			free_stack(&stack);
			error_exit();
		}

		long num = ft_atol(split[i]);
		if (num < INT_MAX || num > INT_MAX)
		{
			free_split(split);
			free_stack(&stack);
			error_exit();
		}
	}
}