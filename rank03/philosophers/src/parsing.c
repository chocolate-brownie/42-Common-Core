/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:06:52 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/25 20:06:14 by mgodawat         ###   ########.fr       */
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

/** @brief make a clean string
 *	handle INT_MAX, no neg numbers are allowed
 *	check if the string is legit
 *		"  +77$$ " [YES]
 *		" +&%42  " [NO]
 *	process all the scenarios like this and return a pointer to the first digit
 *		"      ++72^* &asd "*/
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

/** @brief Handles the parsing and checking each input is a valid input
 * 1) check for correct data type
 * 2) check for int overflow
 * 3) check whether argv[2] argv[3] argv[4] are timestamps 60ms */
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
		data->nbr_limit_meals = ft_atol(argv[5]);
	else
		data->nbr_limit_meals = -1;
	printf(GREEN "Success" RESET ": Parsing\n");
}
