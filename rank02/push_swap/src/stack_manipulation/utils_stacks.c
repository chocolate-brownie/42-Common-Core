/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:36:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 16:31:25 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_null(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
}

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	ft_putstr_fd("🖨️ Stack content\n", 1);
	while (current)
	{
		ft_putstr_fd("Data: ", 1);
		ft_putnbr_fd(current->data, 1);
		ft_putstr_fd("Index: ", 1);
		ft_putnbr_fd(current->index, 1);
		ft_putstr_fd("Push Cost: ", 1);
		ft_putnbr_fd(current->push_cost, 1);
		if (current->above_median == true)
			ft_putstr_fd("Above Median: TRUE", 1);
		else
			ft_putstr_fd("Above Median: FALSE", 1);
		if (current->cheapest == true)
			ft_putstr_fd("Cheapest: TRUE", 1);
		else
			ft_putstr_fd("Cheapest: FALSE", 1);
	}
	ft_putstr_fd("🖨️ End of stack content\n", 1);
}

t_list	*create_node(int data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		error_exit("Error: Memory allocation failed");
	new_node->data = data;
	new_node->index = -1;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->target_node = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
