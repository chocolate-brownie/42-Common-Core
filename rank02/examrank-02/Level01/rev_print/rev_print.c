/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:25:06 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 14:31:48 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a function that takes a string, and displays the string in reverse
followed by a newline.

The original string must not be modified.

You must return the string passed as a parameter.

Your function must be declared as follows:

char *rev_print(char *str);

Examples:

Output :
$> ./a.out | cat -e
dlrow olleH$
$> ./a.out | cat -e
Reverse print$
$> ./a.out | cat -e
$
*/

#include <unistd.h>

char *rev_print(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	while (--i >= 0)
		write(1, &str[i], 1);
	write(1, "\n", 1);
	return str;
}

int main(void)
{
	rev_print("Hello world");
}
