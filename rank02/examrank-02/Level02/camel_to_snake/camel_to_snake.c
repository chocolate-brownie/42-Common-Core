/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:49:23 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 09:54:45 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;

		while (str[i])
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				write(1, "_", 1);
				str[i] += 32;
			}
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
