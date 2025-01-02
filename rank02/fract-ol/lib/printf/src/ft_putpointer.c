/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:25:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/21 16:39:32 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex_unsigned_long(unsigned long n)
{
	int		count;
	char	hex_digit;
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_unsigned_long(n / 16);
	hex_digit = hex_digits[n % 16];
	count += ft_putchar(hex_digit);
	return (count);
}

int	ft_putpointer(void *ptr)
{
	int				count;
	unsigned long	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex_unsigned_long(address);
	return (count);
}
/* int	main(void)
{
	int	x;

	x = 42;
	ft_putpointer(&x);
	write(1, "\n", 1);
	return (0);
} */
