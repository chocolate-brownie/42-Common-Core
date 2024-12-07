/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 04:32:10 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/07 04:33:50 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	handle_sign_and_spaces(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	i = 0;
	sign = handle_sign_and_spaces(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && (str[i]
					- '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return (LONG_MAX);
			return (LONG_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
