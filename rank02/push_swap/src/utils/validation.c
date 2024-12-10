/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:58:14 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/10 01:50:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_valid_input(char **args)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (args[i])
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
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
	int	i;
	int	num1;
	int	j;
	int	num2;

	i = 0;
	while (split_args[i])
	{
		num1 = ft_atol(split_args[i]);
		j = i + 1;
		while (split_args[j])
		{
			num2 = ft_atol(split_args[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_consistent(int argc, char **argv)
{
	bool	spaces;
	bool	direct_nums;
	int		i;

	spaces = false;
	direct_nums = false;
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
			spaces = true;
		else
			direct_nums = true;
		if (spaces && direct_nums)
			return (0);
		i++;
	}
	return (1);
}
