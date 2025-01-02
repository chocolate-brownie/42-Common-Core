/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgodawat <mgodawat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 01:30:22 by mgodawat          #+#    #+#             */
/*   Updated: 2024/06/01 02:01:55 by mgodawat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1 * 1024);
	return (0);
}

/* #include <ctype.h>
#include <stdio.h>

void	test_isalpha(int c)
{
	printf("Character: %c (%d)\n", c, c);
	printf("ft_isalpha return:		%d\n", ft_isalpha(c));
	printf("isalpha return:			%d\n", isalpha(c));
	printf("Match: %s\n", (ft_isalpha(c) == isalpha(c)) ? "Yes" : "No");
	printf("\n");
}

int	main(void)
{
	printf("Testing comparison between isalpha and ft_isalpha:\n\n");
	test_isalpha('A');  // Alphabetic, uppercase
	test_isalpha('z');  // Alphabetic, lowercase
	test_isalpha('0');  // Numeric
	test_isalpha('@');  // Special character
	test_isalpha('a');  // Alphabetic, lowercase
	test_isalpha('Z');  // Alphabetic, uppercase
	test_isalpha('5');  // Numeric
	test_isalpha(' ');  // Space
	test_isalpha('\n'); // Newline
	test_isalpha('!');  // Special character
	return (0);
} */
