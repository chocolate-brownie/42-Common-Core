/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:13:24 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/28 00:33:13 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void print_structure(t_data *data)
{
    int i;

    printf("\n=== STRUCTURE DEBUG INFO ===\n");
    
    // Print general simulation data
    printf("\nSimulation Settings:\n");
    printf("Number of philosophers: %ld\n", data->philo_nbr);
    printf("Time to die: %ld\n", data->time_to_die);
    printf("Time to eat: %ld\n", data->time_to_eat);
    printf("Time to sleep: %ld\n", data->time_to_sleep);
    printf("Must eat count: %ld\n", data->nbr_limit_meals);
    printf("End simulation flag: %s\n", data->end_simulation ? "true" : "false");
    printf("Start simulation time: %ld\n", data->start_simulation);

    // Print philosophers data
    printf("\nPhilosophers Info:\n");
    i = 0;
    while (i < data->philo_nbr)
    {
        printf("\nPhilosopher %d:\n", data->philos[i].philo_id);
        printf("  Meals eaten: %ld\n", data->philos[i].meals_counter);
        printf("  Is full: %s\n", data->philos[i].full ? "true" : "false");
        printf("  Last meal time: %ld\n", data->philos[i].last_meal_time);
        printf("  Left fork ID: %d\n", data->philos[i].left_fork->fork_id);
        printf("  Right fork ID: %d\n", data->philos[i].right_fork->fork_id);
        i++;
    }

    // Print forks data
    printf("\nForks Info:\n");
    i = 0;
    while (i < data->philo_nbr)
    {
        printf("Fork %d initialized\n", data->forks[i].fork_id);
        i++;
    }
    printf("\n===========================\n\n");
}
