/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:03:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 00:33:46 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	forks_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->forks[i].fork_id = i;
		safe_mutex(&data->forks[i].fork, INIT);
		i++;
	}
}
/*
Sets up each philosopher with:

Their seat number (philo_id)
Their meal counter (starts at 0)
Their hunger status (starts not full)
Their last meal time (starts at 0)
Their personal mutex (like their personal space)

Gives them access to their forks:

Even-numbered philosophers get left fork first
Odd-numbered philosophers get right fork first
WARNING: This prevents deadlocks :everyone trying to grab the same fork at once

The key difference between even and odd philosophers grabbing forks is
like having some people pick up their left fork first and others pick up
their right fork first - this prevents everyone from deadlocking by
trying to grab the same fork at the same time.

Would you like me to explain any specific part in more detail?
*/

static void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philos[i].philo_id = i + 1;
		data->philos[i].meals_counter = 0;
		data->philos[i].full = false;
		data->philos[i].last_meal_time = 0;
		data->philos[i].data = data;
		safe_mutex(&data->philos[i].thread_id, INIT);
		if (data->philos[i].philo_id % 2 == 0)
		{
			data->philos[i].left_fork = &data->forks[i];
			data->philos[i].right_fork = &data->forks[(i + 1)
				% data->philo_nbr];
		}
		else
		{
			data->philos[i].right_fork = &data->forks[i];
			data->philos[i].left_fork = &data->forks[(i + 1) % data->philo_nbr];
		}
		i++;
	}
}

void	struct_init(t_data *data)
{
	printf(BLUE "Ongoing" RESET ": struct initializing\n");
	data->end_simulation = false;
	data->start_simulation = 0;
	data->forks = safe_malloc(sizeof(t_fork) * data->philo_nbr);
	data->philos = safe_malloc(sizeof(t_philo) * data->philo_nbr);
	forks_init(data);
	philo_init(data);
	print_structure(data);
	printf(GREEN "Success" RESET ": structure initialized\n");
}
