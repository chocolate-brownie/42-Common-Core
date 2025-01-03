/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 03:52:16 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/03 03:53:39 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	handle_decimals(const char *str, int *i)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 10.0;
	(*i)++;
	while (str[*i] && ft_isdigit(str[*i]))
	{
		fraction += (str[*i] - '0') / divisor;
		divisor *= 10.0;
		(*i)++;
	}
	return (fraction);
}

double	ft_atof(const char *str)
{
	int		i;
	double	result;
	int		sign;

	i = 0;
	result = 0.0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] == '-') ? -1 : 1;
	while (str[i] && ft_isdigit(str[i]))
		result = (result * 10.0) + (str[i++] - '0');
	if (str[i] == '.')
		result += handle_decimals(str, &i);
	return (result * sign);
}
