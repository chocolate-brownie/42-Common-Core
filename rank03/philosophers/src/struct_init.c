/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:03:19 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/26 21:36:43 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void assign_forks(t_philo *philo, t_fork *forks, int position)
{
	int philo_nbr = philo->data->philo_nbr;
	  
}

static void philo_init(t_data *data) 
{
	int i = -1;
	t_philo *philo;

	while (++i < data->philo_nbr)
	{
		philo = data->philos + i;
		philo->philo_id = i + 1;
		philo->meals_counter = 0;
		philo->full = false;
		philo->data = data;
		assign_forks(philo, data->forks, i);
	}
}

void	struct_init(t_data *data)
{
	int i = -1;

	data->end_simulation = false;
	data->philos = safe_malloc(sizeof(t_philo) * data->philo_nbr);
	data->forks = safe_malloc(sizeof(t_fork) * data->philo_nbr);
	while (++i < data->philo_nbr) {
		safe_mutex(&data->forks[i].fork, INIT);
		data->forks[i].fork_id = i;
	}
	philo_init(data);
	return ;
}
