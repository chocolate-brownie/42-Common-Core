/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:22:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/27 16:23:14 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	has_duplicates(t_list *stack)
{
	t_list *current = stack;
	t_list *checker;

	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->data == checker->data)
				return (true);
			checker = checker->next;
		}
		current = current->next;
	}
	return (false);
}