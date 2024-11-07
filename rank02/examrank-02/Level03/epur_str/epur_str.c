/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:51:41 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/07 14:22:13 by mgodawat         ###   ########.fr       */
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
			/* if the current char is a space set flag to 1 to inidicate you
				* should print a space */
			if (ft_isspace(str[i]))
				should_space = 1;
			else
			{
				/* check if I should print a space if I should print one space */
				if (should_space == 1)
					write(1, " ", 1);
				/* after printing the space set the var to 0 since we dont need
					* to print it anymore. */
				should_space = 0;
				/* print the characters */
				write(1, &str[i], 1);
			}
			i++;
		}
	}
	write(STDOUT_FILENO, "\n", 1);
	return (0);
}
