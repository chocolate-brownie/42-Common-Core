/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:19:54 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 15:28:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_resources(t_list **stack, char **split)
{
	while (stack && *stack)
	{
		t_list *temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}

	if (split)
	{
		int i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}