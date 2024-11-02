/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:04:40 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/24 19:44:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/ft_printf.h"

int	convertions(const char option, va_list args)
{
	if (option == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (option == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (option == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (option == 'd' || option == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (option == 'u')
		return (ft_putnbrunsigned(va_arg(args, unsigned int)));
	else if (option == 'x')
		return (ft_puthexnbr(va_arg(args, unsigned long int), 0));
	else if (option == 'X')
		return (ft_puthexnbr(va_arg(args, unsigned long int), 1));
	else
		return (ft_putchar(option));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;
	const char	next_char = *format;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (next_char != '\0')
				count += convertions(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
