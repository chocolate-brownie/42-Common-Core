/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:00:24 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/21 16:42:21 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	conversion(const char option, va_list args)
{
	if (option == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (option == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (option == 'd' || option == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (option == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (option == 'x')
		return (ft_puthex(va_arg(args, unsigned int), 0));
	else if (option == 'X')
		return (ft_puthex(va_arg(args, unsigned int), 1));
	else if (option == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else
		return (ft_putchar(option));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count += conversion(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
