/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:48:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/15 16:50:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	create_stack(t_stack_node **a, char **argv)
{
	t_stack_node	*tail;
	t_stack_node	*new_node;

	tail = *a;
	while (*argv)
	{
		new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
		if (!new_node)
			free_resources(a, argv);
		new_node->value = (int)ft_atol(*argv);
		new_node->next = NULL;
		new_node->prev = tail;
		if (!*a)
			*a = new_node;
		else
			tail->next = new_node;
		tail = new_node;
		argv++;
	}
}

int	stack_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*curr;

	len = 0;
	curr = stack;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}
