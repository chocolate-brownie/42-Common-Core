/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:58:18 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 17:58:44 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *stack)
{
	t_list	*current;

	current = stack;
	printf("🖨️ Stack content:\n");
	while (current)
	{
		printf("Data: %d\n", current->data);
		printf("Index: %d\n", current->index);
		printf("Push Cost: %d\n", current->push_cost);
		printf("Above Median: %s\n", current->above_median ? "TRUE" : "FALSE");
		printf("Cheapest: %s\n", current->cheapest ? "TRUE" : "FALSE");
		printf("-------------------\n");
		current = current->next;
	}
	printf("🖨️ End of stack content\n");
}

void	print_stack_data(t_list *stack_a)
{
	t_list *current;

	current = stack_a;
	printf("🖨️ Stack A Data:\n");
	while (current)
	{
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n🖨️ End of Stack A Data\n");
}