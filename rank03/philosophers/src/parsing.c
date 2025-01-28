/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 04:38:54 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 00:58:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static inline bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static inline bool	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

static const char	*valid_input(const char *str)
{
	int			len;
	const char	*number;

	len = 0;
	while (ft_isspace(*str) == true)
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
		error_exit(RED "Parsing" RESET ": Input is negative\n");
	if (!ft_isdigit(*str))
		error_exit(RED "Parsing" RESET ": Input is invalid digit\n");
	number = str;
	while (ft_isdigit(*str))
	{
		++len;
		++str;
	}
	if (len > 10)
		error_exit(RED "Parsing" RESET ": Input is greater than INT_MAX\n");
	return (number);
}

static long	ft_atol(const char *str)
{
	long	num;

	num = 0;
	str = valid_input(str);
	while (ft_isdigit(*str))
		num = (num * 10) + (*str++ - '0');
	if (num > INT_MAX)
		error_exit(RED "Parsing" RESET ": Input is greater than INT_MAX\n");
	return (num);
}

void	parsing(t_data *data, char **argv)
{
	printf(BLUE "Ongoing" RESET ": Parsing\n");
	data->philo_nbr = ft_atol(argv[1]);
	data->time_to_die = ft_atol(argv[2]) * 1000;
	data->time_to_eat = ft_atol(argv[3]) * 1000;
	data->time_to_sleep = ft_atol(argv[4]) * 1000;
	if (data->time_to_die < 60000 || data->time_to_eat < 60000
		|| data->time_to_sleep < 60000)
		error_exit(RED "Parsing" RESET ": Use timestamps major than 60ms\n");
	if (argv[5])
	{
		data->nbr_limit_meals = ft_atol(argv[5]);
		if (data->nbr_limit_meals <= 0)
			error_exit(RED "Parsing" RESET ": Invalid number of meals\n");
	}
	else
		data->nbr_limit_meals = -1;
	printf(GREEN "Success" RESET ": Parsing\n");
}
