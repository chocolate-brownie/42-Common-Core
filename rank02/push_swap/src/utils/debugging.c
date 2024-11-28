/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugging.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:53:30 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 17:51:22 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: print_stack
** ----------------------
** Prints the numbers in the stack from top to bottom.
**
** stack: The stack to print.
** name: The name of the stack (e.g., "a" or "b").
*/
void	print_stack(t_stack *stack, char *name)
{
	t_stack_node	*current;

	if (!stack || !stack->head)
	{
		printf("Stack %s is empty.\n", name);
		return ;
	}
	printf("Stack %s: ", name);
	current = stack->head;
	while (current)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}
