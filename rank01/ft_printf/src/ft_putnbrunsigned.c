/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:45:55 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/24 19:50:04 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbrunsigned(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (ft_putchar('0'));
	if (nbr / 10 != 0)
		count += ft_putnbrunsigned(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}
