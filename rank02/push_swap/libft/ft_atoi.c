/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:13:28 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/08 17:46:53 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	digit;

	sign = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (result * sign);
}

/* FUNCTION ft_atoi(str)
	IF str IS NULL
		RETURN 0

	SET index TO 0
	SET sign TO 1
	SET result TO 0

	// Skip leading whitespace
	WHILE str[index] IS whitespace
		INCREMENT index

	// Check for sign
	IF str[index] IS '-'
		SET sign TO -1
		INCREMENT index
	ELSE IF str[index] IS '+'
		INCREMENT index

	// Process each digit
	WHILE str[index] IS a digit
		SET digit TO ASCII value of str[index] - ASCII value of '0'
		SET result TO result * 10 + digit
		INCREMENT index

	RETURN result * sign
END FUNCTION */
