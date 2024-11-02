/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:25:49 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/01 18:43:51 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk_a;
	t_list	*stk_b;

	init_stack_null(&stk_a, &stk_b);
	stk_a = handle_arguments(argc, argv);
	print_list(stk_a);
	/*
	if (!stk_a || check_duplicates(stk_a))
		error_exit();
	if (!stack_sorted(stk_a))
	{
		if (stack_len(stk_a) == 2)
			sa(&stk_a, false);
		else if (stack_len(stk_a) == 3)
			sort_three(&stk_a);
		else
			turk_algorithm(&stk_a, stk_b);
	}
	*/
	free_stack(&stk_a);
	return (0);
}

void	print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
}

t_list	*handle_arguments(int argc, char **argv)
{
	t_list	*stk_a;
	int		i;

	stk_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		error_exit();
	if (argc == 2)
		stk_a = split_and_push(argv[1], stk_a);
	else
	{
		i = 1;
		while (i < argc)
		{
			stk_a = push_numbers_to_stack(argv[i], stk_a);
			i++;
		}
	}
	return (stk_a);
}
