/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:57:53 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 01:24:24 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	print_usage(void)
{
	printf(BLUE "Usage" RESET ": ./philo " BOLD "<nbr> <t_die> "
		"<t_eat> <t_sleep> " RESET "[" BOLD "meals" RESET "]\n");
	printf("All arguments must be positive numbers\n\n");
}

void	error_exit(const char *message)
{
	printf("\n%s", message);
	print_usage();
	exit(EXIT_FAILURE);
}

void	*safe_malloc(size_t bytes)
{
	void	*var;

	var = malloc(bytes);
	if (!var)
		error_exit(RED "Error" RESET ": allocating memory\n");
	return (var);
}

void clean_up(t_data *data)
{
	return;
}
