/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 18:01:59 by mgodawat          #+#    #+#             */
/*   Updated: 2024/11/02 19:17:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *str1 = argv[1];
		char *str2 = argv[2];
		unsigned char seen[256] = {0};

		int i = 0;
		int k = 0;

		while (str1[i])
		{
			while (str2[k])
			{
				if (!seen[(unsigned char)str1[i]]) {
					write(1, &str1[i], 1);
					seen[(unsigned char)str1[i]] = 1;
				}
				break;
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}
