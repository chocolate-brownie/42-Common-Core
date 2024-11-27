/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:08:03 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:22:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* @note: if the arguments are not a single string but a bunch of argument
vectors take the current str and push it to stack_a one by one make sure you
check whether the token is a valid input, check for integer overflows and
duplicates */
t_list	*push_numbers_to_stack(char *token, t_list *stack_a)
{
	long	num;

	printf("🔧 [RUNNING] push_numbers_to_stack function\n");
	if (!is_valid_input(token))
	{
		free_resources(&stack_a, NULL);
		error_exit();
	}
	num = ft_atol(token);
	if (num < INT_MIN || num > INT_MAX)
	{
		free_resources(&stack_a, NULL);
		error_exit();
	}
	if (check_duplicates(stack_a, (int)num))
	{
		free_resources(&stack_a, NULL);
		error_exit();
	}
	append_node(&stack_a, (int)num);
	printf("🔧 [ENDING] push_numbers_to_stack function\n");
	return (stack_a);
}
