/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:42:47 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/02 22:56:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/** @return the number of digits processed and updates position */
static int	check_digits(const char **str)
{
	int	count;

	count = 0;
	while (ft_isdigit(**str))
	{
		count++;
		(*str)++;
	}
	return (count);
}

/** @brief a funciton that checks if string is a valid floating point number
 * supports formats like:
 * - "42"        (integer)
 * - "-42"       (negative)
 * - "42.42"     (decimal)
 * - "-42.42"    (negative decimal)
 */
bool	is_valid_number(char *str)
{
	const char	*ptr;
	int			digits;
	bool		has_sign;
	bool		has_dots;

	if (!str || !*str)
		return (false);
	ptr = str;
	has_sign = (*ptr == '+' || *ptr == '-');
	if (has_sign)
		ptr++;
	digits = check_digits(&ptr);
	has_dots = (*ptr == '.');
	if (has_dots)
	{
		ptr++;
		digits += check_digits(&ptr);
	}
	return (digits > 0 && *ptr == '\0');
}
/* void	test_number_format(char *str)
{
	printf("Testing '%s': %s\n", str,
		is_valid_number(str) ? "valid" : "invalid");
}

int	main(void)
{
	test_number_format("42");
	test_number_format("-42");
	test_number_format("42.42");
	test_number_format("-42.42");
	test_number_format(".42");
	test_number_format("42.");
	test_number_format("4.2.2");
	test_number_format("abc");
	return (0);
} */