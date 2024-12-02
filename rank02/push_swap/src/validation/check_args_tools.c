/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:55:31 by mgodawat          #+#    #+#             */
/*   Updated: 2024/12/02 16:56:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_integer(char *str)
{
	long	number;
	char	*converted;
	int		is_valid;

	if (!str || *str == '\0')
		return (0);
	number = ft_atol(str);
	if (number > INT_MAX || number < INT_MIN)
		return (0);
	converted = ft_itoa((int)number);
	if (!converted)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	is_valid = (ft_strcmp(str, converted) == 0);
	free(converted);
	return (is_valid);
}

int	has_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
