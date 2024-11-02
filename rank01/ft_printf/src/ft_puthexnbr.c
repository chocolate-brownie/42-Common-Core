/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:30:36 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/24 19:43:00 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthexnbr(unsigned int nbr, int uppercase)
{
	int		count;
	char	*hex_chars;

	count = 0;
	if (uppercase == 1)
		hex_chars = "0123456789ABCDEF";
	else
		hex_chars = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_puthexnbr(nbr / 16, uppercase);
	count += ft_putchar(hex_chars[nbr % 16]);
	return (count);
}
