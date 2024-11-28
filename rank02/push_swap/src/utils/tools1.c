/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:24:55 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 14:53:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *error_msg)
{
	if (error_exit)
	{
		ft_putstr_fd(error_msg, 2);
		exit(EXIT_FAILURE);
	}
}

void	free_resources(t_stack *stack, char **split)
{
	t_list	*current;
	t_list	*temp;
	int		i;

	free_stack(split);
	if (stack != NULL)
	{
		current = stack->bgn_list != NULL ? *(stack->bgn_list) : NULL;
		while (current != NULL)
		{
			temp = current->next;
			free(current->content);
			free(current);
			current = temp;
		}
		if (stack->bgn_list != NULL)
			free(stack->bgn_list);
		free(stack);
	}
}

void	free_stack(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
