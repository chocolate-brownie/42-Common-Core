/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:48:34 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/07 03:52:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	create_stack(t_stack_node **a, char **argv)
{
	while (*argv)
	{
		long nbr = ft_atol(*argv);
		t_stack_node *new_node = malloc(sizeof(t_stack_node));
		if (!new_node)
		{
		}
	}
}