/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:10:01 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/24 18:53:38 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned long int nbr)
{
	int		count;
	char	hex_digit;
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_puthex(nbr / 16);
	hex_digit = hex_chars[nbr % 16];
	count += ft_putchar(hex_digit);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	unsigned long int	address;
	int					count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long int)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(address);
	return (count);
}
