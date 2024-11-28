/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:24:55 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/28 11:33:16 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *error_msg)
{
	if (error_exit)
	{
		ft_putstr_fd(error_msg, 2);
		exit(EXIT_FAILURE);
	}
}
