/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:41:29 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/15 16:43:57by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// ***** Linked List Structure *****
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	int					above_median;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void	print_stack_details(t_stack_node *stack, char stack_name)
{
	int	position;

	position = 0;
	if (!stack)
	{
		printf("Stack %c is empty\n", stack_name);
		return ;
	}
	printf("Stack %c details:\n", stack_name);
	while (stack)
	{
		printf("Position %d: \n", position);
		printf("  Value: %d\n", stack->value);
		printf("  Current position: %d\n", stack->current_position);
		printf("  Final index: %d\n", stack->final_index);
		printf("  Push price: %d\n", stack->push_price);
		printf("  Above median: %d\n", stack->above_median);
		if (stack->target_node)
			printf("  Target value: %d\n", stack->target_node->value);
		printf("\n");
		stack = stack->next;
		position++;
	}
	printf("------------------------\n");
}

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

int	main(void)
{
    
}