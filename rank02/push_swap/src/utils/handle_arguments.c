/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arguments.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:59:16 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:04:58 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* write a function that returns a valid stack_a after reviewing all the
necessary checks... */
t_list	*handle_arguments(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	printf("🔧 [RUNNING] handle_argument function\n");
	stack_a = NULL;
	/* if the condition is a single string scenario such as push_swap "12 78 6"
	simply split the string and push the numbers to stack_a */
	if (argc == 2)
		stack_a = split_and_push(argv[1], stack_a);
	else if (argc > 2)
	{
		/* if not check each argument is a valid integer that we can use... if
		so push each number to stack_a */
		i = 1;
		if (!is_valid_input(argv[i]))
			error_exit();
		while (i < argc)
			stack_a = push_numbers_to_stack(argv[i++], stack_a);
	}
	if (!stack_a)
		error_exit();
	printf("🔧 [ENDING] handle_argument function successfully\n");
	return (stack_a);
}

bool	is_valid_input(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
