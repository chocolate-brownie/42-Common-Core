/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:44 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 17:23:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*handle_arguments(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	validate_mixed_input(argc, argv);
	if (argc == 2)
		stack_a = handle_single_string(argv[1]);
	else if (argc > 2)
		stack_a = handle_multiple_arguments(argc, argv);
	else
		error_exit("[ERROR] Invalid arguments");
	return (stack_a);
}

t_list	*handle_single_string(char *arg)
{
	t_list	*stack;
	long	num;
	char	**split;
	int		i;

	stack = NULL;
	split = ft_split(arg, ' ');
	if (!split)
		error_exit("[ERROR] Splitting");
	i = 0;
	while (split[i])
	{
		if (!is_numeric(split[i]))
			error_exit("[ERROR] Arguments are not numeric");
		num = ft_atol(split[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit("[ERROR] Integer overflow");
		add_to_stack(&stack, (int)num);
		i++;
	}
	free_resources(NULL, split);
	if (has_duplicates(stack))
		error_exit("[ERROR] Contains duplicates");
	return (stack);
}

t_list	*handle_multiple_arguments(int argc, char **argv)
{
	t_list	*stack;
	long	num;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i]))
			error_exit("[ERROR] Invalid arguments");
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit("[ERROR] Integer overflow");
		add_to_stack(&stack, (int)num);
		i++;
	}
	if (has_duplicates(stack))
		error_exit("[ERROR] Contains duplicates");
	return (stack);
}
