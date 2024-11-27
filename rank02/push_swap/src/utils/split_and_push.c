/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_and_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 13:12:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:49:40 by mgodawat         ###   ########.fr       */
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
t_list	*split_and_push(char *str, t_list *stack_a)
{
	char	**split;
	int		i;

	printf("\t🔧 [RUNNING] split_and_push function\n");
	split = ft_split(str, ' ');
	if (!split)
		error_exit();
	i = 0;
	while (split[i])
	{
		validate_and_push(split[i], &stack_a, split);
		i++;
	}
	free_resources(NULL, split);
	printf("\t🔧 [ENDING] split_and_push function\n");
	return (stack_a);
}

void	validate_and_push(char *token, t_list **stack, char **split)
{
	long	num;

	printf("\t\t🔧 [RUNNING] validate_and_push function\n");
	if (!is_valid_input(token))
	{
		free_resources(stack, split);
		error_exit();
	}
	num = ft_atol(token);
	if (num > INT_MAX || num < INT_MIN)
	{
		free_resources(stack, split);
		error_exit();
	}
	if (check_duplicates(*stack, (int)num))
	{
		free_resources(stack, split);
		error_exit();
	}
	append_node(stack, (int)num);
	printf("\t\t🔧 [ENDING] validate_and_push function\n");
}

bool	check_duplicates(t_list *stack, int num)
{
	while (stack)
	{
		if (stack->data == num)
			return (true);
		stack = stack->next;
	}
	return (false);
}
