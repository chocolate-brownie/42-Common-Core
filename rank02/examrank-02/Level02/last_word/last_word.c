/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:22:05 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 19:40:13 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;

		while (str[i])
			i++;
		i--;

		/* finding the end of the last word skipping spaces
		until arrives at something */
		while (i >= 0 && ft_isspace(str[i]))
			i--;
		
		// save that spot to a var
		int end = i;
		/* traverse to the beginning of the word i-- until 
		I find a sapce */
		while (i >= 0 && !ft_isspace(str[i]))
			i--;

		/* found a space!! now +1 so the i is on a character */
		int start = i + 1;
		/* now until you reach the end of the word with the var
		you stored before write */
		while (start <= end)
			write(1, &str[start++], 1);

	}
	write(1, "\n", 1);
	return 0;
}
