/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:40:13 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/04 09:47:30 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;

		while (str[i])
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = 'a' + ('z' - str[i]);
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = 'A' + ('Z' - str[i]);
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
