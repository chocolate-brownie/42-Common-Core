/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:24:06 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 14:27:01 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	main(int argc, char *argv[])
{
	char	*str;
	int		i;
	int		should_space;

	if (argc == 2)
	{
		str = argv[1];
		i = 0;
		while (ft_isspace(str[i]))
			i++;
		should_space = 0;
		while (str[i])
		{
			if (ft_isspace(str[i]))
				should_space = 1;
			else
			{
				if (should_space == 1)
					write(1, "   ", 3);
				should_space = 0;
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
