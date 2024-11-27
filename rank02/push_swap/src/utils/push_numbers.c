/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:08:03 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 12:14:41 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* if the arguments are not a single string but a bunch of argument vectors
take the current str and push it to stack_a one by one */
t_list	*push_numbers_to_stack(char *token, t_list *stack_a)
{
	if (!is_valid_input(token))
	{
		free_resources(&stack_a, NULL);
		error_exit();
	}
}