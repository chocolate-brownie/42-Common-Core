/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:32:25 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 15:47:29 by mgodawat         ###   ########.fr       */
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
				str[i] = (str[i] - 'a' + 13) % 26 + 'a';
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = (str[i] - 'A' + 13) % 26 + 'A';
			write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
