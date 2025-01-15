/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:26:52 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/18 15:52:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (*str)
	{
		write(1, str++, 1);
		count++;
	}
	return (count);
}
