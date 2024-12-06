/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:58:14 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/06 15:13:26 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_valid_input(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	duplicates(char **split_args)
{
	int i = 0;
	while (split_args[i])
	{
		int num1 = ft_atol(split_args[i]);
		int j = i + 1;
		while (split_args[j])
		{
			int num2 = ft_atol(split_args[j]);
			if (num1 == num2)
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}
