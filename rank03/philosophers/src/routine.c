/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:29:36 by mgodawat          #+#    #+#             */
/*   Upded: 2025/02/13 21:21:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

/**
00000  1 has taken a fork
00000  1 has taken a fork
00000  1 is eating
00000  3 has taken a fork
00000  3 has taken a fork
00000  3 is eating
00200  1 is sleeping
00200  2 has taken a fork
00200  2 has taken a fork

1. Start THINKING
2. When ready to eat, they need to:
   - Try to take first fork (usually left)
   - Try to take second fork (usually right)
   - Once they have both forks, they can EAT
3. After EATING:
   - Put down both forks
   - Go to SLEEPING state
4. After SLEEPING:
   - Go back to THINKING

And this cycle repeats until either:
- A philosopher dies (if they don't eat within time_to_die)
- All philosophers have eaten enough times (if must_eat_times is specified) */

/** Add a delay if the number of philosophers are odd to prevent deadlock
usleep(200000); - Sleeps for 200ms, but can't interrupt if someone dies
ft_usleep(200, setting); - break early if someone dies, more precise timing */

void	thinking(t_philo *philo)
{
	print_message(philo->settings, philo->id, THINKING);
	philo->status = EATING;
}

/**
 * 2. If forks are successfully grabbed:
 *    - Updates philosopher's last meal timestamp
 *    - Prints "is eating" message
 *    - Sleeps for time_to_eat duration
 *    - Increments number of meals eaten
 *    - Checks if philosopher has reached must_eat_times (if specified) - Releases both forks in reverse order of acquisition - Changes philosopher status to SLEEPING During any step, if another philosopher dies, the function should: - Release any held forks
 *    - Return without completing the eating process
 */

void	eating(t_philo *philo)
{
	unsigned int first_fork;
	unsigned int second_fork;

	if (forks_grabbed(philo))
	{
		safe_mutex_handle(philo->settings->mtx_meal, LOCK);
		gettimeofday(&philo->settings->last_meal[philo->id - 1], NULL);
		safe_mutex_handle(philo->settings->mtx_meal, UNLOCK);
		print_message(philo->settings, philo->id, EATING);
		ft_usleep(philo->settings->time_to_eat, philo->settings);
		philo->num_meals++;
		if (philo->num_meals >= philo->settings->must_eat_times)
		{
			safe_mutex_handle(philo->settings->mtx_full, LOCK);
			philo->settings->fulled_phils++;
			safe_mutex_handle(philo->settings->mtx_full, UNLOCK);
		}
		// how do i release the forks?
	}
	philo->status = SLEEPING;
}

void	sleeping(t_philo *philo);
