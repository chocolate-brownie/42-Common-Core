/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:20:56 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 22:45:52 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (-1);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

static void	create_philo_threads(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nbr)
		safe_thread(&data->philos[i].thread, philo_routine, &data->philos[i],
			CREATE);
}

static void wait_for_threads(t_data *data)
{
	int i = -1;
	while (++i < data->philo_nbr)
		safe_thread(&data->philos[i].thread, NULL, NULL, JOIN);
	safe_thread(&data->monitor, NULL, NULL, JOIN);
}

bool	start_simulation(t_data *data)
{
	printf(BLUE "Ongoing" RESET ": Starting simulation\n");
	data->start_simulation = get_current_time();
	create_philo_threads(data);
	safe_thread(&data->monitor, &monitor_routine, data, CREATE);
	wait_for_threads(data);
	printf(GREEN "Success" RESET ": Simulation completed\n");
	return (true);
}
