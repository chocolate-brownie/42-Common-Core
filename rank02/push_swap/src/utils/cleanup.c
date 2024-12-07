/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:58:17 by milan-godaw       #+#    #+#             */
/*   Updated: 2024/12/07 04:02:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*current;
	t_stack_node	*temp;

	if (stack && *stack)
	{
		current = *stack;
		while (current)
		{
			temp = current->next;
			free(current);
			current = temp;
		}
		*stack = NULL;
	}
}

void	free_split(char **split_args)
{
	int	i;

	if (split_args)
	{
		i = 0;
		while (split_args[i])
		{
			free(split_args[i]);
			i++;
		}
		free(split_args);
	}
}

void	free_resources(t_stack_node **stack, char **split_args)
{
	if (stack)
		free_stack(stack);
	if (split_args)
		free_split(split_args);
	error_exit();
}