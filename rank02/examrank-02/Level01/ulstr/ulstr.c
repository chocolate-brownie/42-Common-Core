/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 16:21:56 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 16:29:17 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				str[i] = str[i] -= 32;
			else if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] += 32;
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
