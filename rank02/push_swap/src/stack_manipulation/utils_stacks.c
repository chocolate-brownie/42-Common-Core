/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:36:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 15:54:14 by mgodawat         ###   ########.fr       */
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
	t_list *current = stack;

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