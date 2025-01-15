/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:42:46 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/21 16:19:49 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2147483648");
		return (count);
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n / 10 != 0)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
// #include <stdio.h>

// int	main(void)
// {
// 	ft_putnbr(-42);
// }
