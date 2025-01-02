/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:44:09 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/20 16:10:15 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_puthex(unsigned int n, int uppercase)
{
	int		count;
	char	hex_digit;
	char	*hex_digits;

	count = 0;
	if (uppercase == 1)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex(n / 16, uppercase);
	hex_digit = hex_digits[n % 16];
	count += ft_putchar(hex_digit);
	return (count);
}
/* int	main(void)
{
	write(1, "Lowercase Hex: ", 15);
	ft_puthex(255, 0);
	write(1, "\n", 1);
	write(1, "Uppercase Hex: ", 15);
	ft_puthex(255, 1);
	write(1, "\n", 1);
	return (0);
} */
