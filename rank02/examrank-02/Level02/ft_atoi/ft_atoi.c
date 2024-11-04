/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:03:08 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 10:12:11 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str) {
	int result = 0;
	int i = 0;
	int sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return result * sign;
}
