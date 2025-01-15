/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:35:24 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/20 17:35:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	conversion(const char option, va_list args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putunsigned(unsigned int n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, int uppercase);
int	ft_putpointer(void *ptr);
int	ft_puthex_unsigned_long(unsigned long n);
#endif
