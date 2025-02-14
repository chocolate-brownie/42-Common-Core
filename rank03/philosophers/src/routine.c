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

/** NOTE: 
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


/** NOTE: Add a delay if the number of philosophers are odd to prevent deadlock
using "usleep" function but the delay can be broken if someone dies 
usleep(200000); - Sleeps for 200ms, but can't interrupt if someone dies
ft_usleep(200, setting); - break early if someone dies, more precise timing */

void	thinking(t_philo *philo)
{
	print_message(philo->settings, philo->id, THINKING);
	philo->status = EATING;
}

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
