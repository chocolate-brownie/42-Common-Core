/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:51:47 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/27 16:53:02 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

double	ft_atof(const char *str)
{
	double		result;
	double		decimal;
	int			sign;
	const char	*ptr = str;

	result = 0;
	decimal = 0;
	sign = 1;
	if (*ptr == '-' && ptr++)
		sign = -1;
	while (*ptr && *ptr != '.')
		result = result * 10 + (*ptr++ - '0');
	if (*ptr == '.')
		ptr++;
	while (*ptr)
		decimal = decimal * 10 + (*ptr++ - '0');
	while (decimal >= 1)
		decimal /= 10;
	return (sign * (result + decimal));
}
