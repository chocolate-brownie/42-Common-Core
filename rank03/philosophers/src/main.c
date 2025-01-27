/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:46:00 by mgodawat          #+#    #+#             */
/*   Updated: 2025/01/27 23:12:06 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		printf(GREEN "Success" RESET ": Arguments\n");
		parsing(&data, argv);
		struct_init(&data);
		/* start_simulation(&data); // TODO: */
		/* clean_up(&data); // TODO: */
	}
	else
		error_exit(RED "Error" RESET ": Invalid arguments\n");
	return (0);
}
